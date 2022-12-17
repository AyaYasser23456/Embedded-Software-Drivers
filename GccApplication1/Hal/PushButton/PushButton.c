/*
 * BushButton.c
 *
 * Created: 9/30/2022 7:04:10 PM
 *  Author: Aya
 */ 

#include "PushButton.h"

void H_PushButton_Init(u8 Local_u8_ButtonPin)
{
	M_DIO_PinMode(Local_u8_ButtonPin,INPUT);
}

u8 H_PushButton_Read(u8 Local_u8_ButtonPin)
{
	u8 Local_u8_Reading = 0;
	Local_u8_Reading = M_DIO_PinRead(Local_u8_ButtonPin);
	return Local_u8_Reading;
}