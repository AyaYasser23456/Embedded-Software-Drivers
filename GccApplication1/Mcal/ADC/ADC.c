/*
 * ADC.c
 *
 * Created: 10/21/2022 10:10:26 PM
 *  Author: Aya
 */ 

#include "ADC.h"

void M_ADC_ADCInt(u8 Local_u8_ADC_PIN)
{
	#if		REF_SELECT	==	AREF
	ClrBit(ADMUX,7);
	ClrBit(ADMUX,6);
	#elif	REF_SELECT	==	AVCC
	ClrBit(ADMUX,7);
	SetBit(ADMUX,6);	
	#elif	REF_SELECT	==	Reserved
	SetBit(ADMUX,7);
	ClrBit(ADMUX,6);
	#elif	REF_SELECT	==	Int_2V56
	SetBit(ADMUX,7);
	SetBit(ADMUX,6);
	#endif
	
	#if		ADJUST_MODE		==	RIGHT_ADJUST
	SetBit(ADMUX,5);
	#elif	ADJUST_MODE		==	LEFT_ADJUST
	ClrBit(ADMUX,5);
	#endif
		
	ADMUX	=	(ADMUX & 0xE0) | (Local_u8_ADC_PIN & 0x1F);	
	
	#if		PRESCALER	==		_128
	SetBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	#elif	PRESCALER	==		_64
	ClrBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	#elif	PRESCALER	==		_32
	SetBit(ADCSRA,0);
	ClrBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	#endif
	
	//To Enable ADC Interrupt
	//SetBit(ADCSRA,3);
	//to enable Global interrupt
	//SetBit(SREG,7);
	
	//To Enable Auto Trigger
	SetBit(ADCSRA,5);
	//To Enable ADC
	SetBit(ADCSRA,7);
}

u16 M_ADC_ADCRead(void)
{
	//To Start conversation
	SetBit(ADCSRA,6);
	while(GetBit(ADCSRA,4) == 0);
	ClrBit(ADCSRA,4);
	ClrBit(ADCSRA,6);
	return	(GetBit(ADCH,1) ^ GetBit(ADCH,0) ^ ADCL);
}

//ISR(ADC_vect)
//{
	
//}