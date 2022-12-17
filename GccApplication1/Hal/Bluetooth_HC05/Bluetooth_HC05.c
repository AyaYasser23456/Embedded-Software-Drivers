/*
 * Bluetooth_HC05.c
 *
 * Created: 11/12/2022 5:15:59 PM
 *  Author: Aya Yasser
 */ 

#include "Bluetooth_HC05.h"

void H_Bluetooth_HC05_Init()
{
	M_UART_UARTInit();
}

void H_Bluetooth_HC05_Send(u8 Local_u8_Data)
{
	M_UART_UARTWrite(Local_u8_Data);
}

u8 H_Bluetooth_HC05_Receive()
{
	u8 Local_u8_Data = 0;
	Local_u8_Data = M_UART_UARTRead();
	return Local_u8_Data;
}
