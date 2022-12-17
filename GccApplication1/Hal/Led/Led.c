/*
 * Led.c
 *
 * Created: 9/30/2022 7:57:18 PM
 *  Author: Aya
 */ 
#include "Led.h"

void H_LED_LedInit(u8 Local_u8_LedPin)
{
	M_DIO_PinMode(Local_u8_LedPin,OUTPUT);
}

void H_LED_LedOn(u8 Local_u8_LedPin)
{
	M_DIO_PinWrite(Local_u8_LedPin,HIGH);
}

void H_LED_LedOff(u8 Local_u8_LedPin)
{
	M_DIO_PinWrite(Local_u8_LedPin,LOW);
}

void H_LED_LedTog(u8 Local_u8_LedPin)
{
	M_DIO_PinTog(Local_u8_LedPin);	
}

void H_LED_LedBlank(u8 Local_u8_LedPin)
{
		M_DIO_PinWrite(Local_u8_LedPin,HIGH);
		_delay_ms(300);
		M_DIO_PinWrite(Local_u8_LedPin,LOW);
}