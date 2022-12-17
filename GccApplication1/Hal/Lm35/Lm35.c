/*
 * Lm35.c
 *
 * Created: 10/22/2022 12:18:12 AM
 *  Author: Aya
 */ 

#include "Lm35.h"

void H_Lm35_Lm35Int(void)
{
	M_ADC_ADCInt(Lm35_PIN);
}

f32 H_Lm35_Lm35Read(void)
{
	u16 Local_u16_Reading =	M_ADC_ADCRead();
	u16 Local_u16_Temp = (((u32)Local_u16_Reading *500) / 1024);
	return	Local_u16_Temp;
}