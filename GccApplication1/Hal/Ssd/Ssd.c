/*
 * Ssd.c
 *
 * Created: 10/14/2022 5:42:41 PM
 *  Author: Aya
 */ 

#include "Ssd.h"

void H_Ssd_SsdInit(void)
{
	M_DIO_PinMode(SSD_PIN_A,OUTPUT);
	M_DIO_PinMode(SSD_PIN_B,OUTPUT);
	M_DIO_PinMode(SSD_PIN_C,OUTPUT);
	M_DIO_PinMode(SSD_PIN_D,OUTPUT);
	
	M_DIO_PinMode(SSD_PIN_EN1,OUTPUT);
	M_DIO_PinMode(SSD_PIN_EN2,OUTPUT);
		
}
void H_Ssd_SsdDisplay(u8 Local_u8_Number)
{
	u8 Local_u8_RightDigit = Local_u8_Number % 10;
	u8 Local_u8_LeftDigit  = Local_u8_Number / 10;
	
	M_DIO_PinWrite(SSD_PIN_EN1,LOW);
	M_DIO_PinWrite(SSD_PIN_EN2,HIGH);
	
	SSD_DATA_PORT = ((Local_u8_LeftDigit << 4) | (SSD_DATA_PORT & 0x0F));
	_delay_ms(50);
	M_DIO_PinWrite(SSD_PIN_EN1,HIGH);
	M_DIO_PinWrite(SSD_PIN_EN2,LOW);
	SSD_DATA_PORT = ((Local_u8_RightDigit << 4) | (SSD_DATA_PORT & 0x0F));
	_delay_ms(2);	
}