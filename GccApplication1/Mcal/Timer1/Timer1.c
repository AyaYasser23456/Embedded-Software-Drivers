/*
 * Timer1.c
 *
 * Created: 10/28/2022 11:25:22 PM
 *  Author: Aya Yasser
 */ 
#include "Timer1.h"

void M_Pwm1_Init(void)
{
	SetBit(DDRD,5);   // to make OC1A as output
	// to select non inverted mode reg 'A'
	ClrBit(TCCR1A,6);
	SetBit(TCCR1A,7);
	// To select ICR1 as top
	ClrBit(TCCR1A,0);
	SetBit(TCCR1A,1);
	SetBit(TCCR1B,3);
	SetBit(TCCR1B,4);
}
void M_Pwm1_SetPwmFrequancy(u16 Local_u16_Freq)
{
	ICR1 = ((CRYSTAL_FREQ * 1000000) / (Timer1_PRE_SCALER_DF * Local_u16_Freq));
}
void M_Pwm1_SetDutyCycle(f32 Local_f32_Dutycylce)
{
	OCR1A =  (((Local_f32_Dutycylce * ICR1) / 100) - 1);
}

void M_Pwm1_Start(void)
{
	#if		Timer1_PRE_SCALER_DF	==	1024
	SetBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2);
	
	#elif	Timer1_PRE_SCALER_DF	==	256
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	SetBit(TCCR1B,2);
	
	#elif	Timer1_PRE_SCALER_DF	==	64
	SetBit(TCCR1B,0);
	SetBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
	#endif
}
void M_Pwm1_Stop(void)
{
	ClrBit(TCCR1B,0);
	ClrBit(TCCR1B,1);
	ClrBit(TCCR1B,2);
}