/*
 * ExtInt.c
 *
 * Created: 10/14/2022 9:45:19 PM
 *  Author: Aya
 */ 

#include "ExtInt.h"

void (*ExtInt_void_Callback)(void) = NULL_;

void M_ExtInt_Init(void)
{
	#if SENSE_CONTROL		==	RISING_EDGE
	SetBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif SENSE_CONTROL		==	FALLING_EDGE
	ClrBit(MCUCR,0);
	SetBit(MCUCR,1);
	
	#elif SENSE_CONTROL		==	ANY_L_CHENGE
	SetBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#elif SENSE_CONTROL		==	LOW_LEVEL
	ClrBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#endif
	//TO enable INT0 interrupt
	SetBit(GICR,6);
	//to enable Global interrupt
	SetBit(SREG,7);
}

void M_ExtInt_SetCallBack(void (*Local_void_Ptr)(void))
{
	ExtInt_void_Callback=Local_void_Ptr;
}

ISR(INT0_vect)
{
	
	ExtInt_void_Callback();// -> callback function
}