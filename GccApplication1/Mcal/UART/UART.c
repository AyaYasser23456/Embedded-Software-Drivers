/*
 * UART.c
 *
 * Created: 11/12/2022 2:54:45 PM
 *  Author: Aya Yasser
 */ 
#include "UART.h"

void M_UART_UARTInit(void)
{
	M_DIO_PinMode(PD0,INPUT);		//To Make RX as Input
	M_DIO_PinMode(PD1,OUTPUT);		//To Make TX as Output
	
	u8 Local_u8_UCSRC_Value = 0;
	SetBit(Local_u8_UCSRC_Value,7);		// To select UCSRC Register
	ClrBit(Local_u8_UCSRC_Value,6);		//To select Asynch Mode
	
	#if		PARITY_MODE     ==    PARTY_DISABLE
	ClrBit(Local_u8_UCSRC_Value,5);
	ClrBit(Local_u8_UCSRC_Value,4);
	#elif		PARITY_MODE     ==    EVEN
	SetBit(Local_u8_UCSRC_Value,5);
	ClrBit(Local_u8_UCSRC_Value,4);	
	#elif		PARITY_MODE     ==    ODD
	SetBit(Local_u8_UCSRC_Value,5);
	SetBit(Local_u8_UCSRC_Value,4);
	#endif
	
	ClrBit(Local_u8_UCSRC_Value,3); //To Select one Stop bit
	
	//To select 8-char size
	ClrBit(UCSRB,2);
	SetBit(Local_u8_UCSRC_Value,2);
	SetBit(Local_u8_UCSRC_Value,1);
	
	UBRRL = 103;		//to select 9600 Boud Rate
	UCSRC = Local_u8_UCSRC_Value;	
	SetBit(UCSRB,4);	// To Enable RX
	SetBit(UCSRB,3);	// To Enable TX
	
}

void M_UART_UARTWrite(u8 Local_u8_Data)
{
	UDR = Local_u8_Data;
	while(GetBit(UCSRA,6) == 0);
	
}

u8 M_UART_UARTRead(void)
{
	while(GetBit(UCSRA,7) == 0);
	return UDR;
}