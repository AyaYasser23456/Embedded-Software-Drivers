/*
 * Timer0.c
 *
 * Created: 10/22/2022 2:46:25 PM
 *  Author: Aya
 */ 

#include "Timer0.h"

void(*Timer0_void_CallBack)(void) = NULL_;
u32 Timer0_u32_NumOfOverFlows     = 0;
u8  Timer0_u8_RemTicks            = 0;
u32 Timer0_u32_NumOfCompMatch     = 0;

void M_Timer0_Timer0Init(void)
{
	#if		TIMER0_MODE	==	NORMAL_MODE	
	ClrBit(TCCR0,6);
	ClrBit(TCCR0,3);
	//To Enable timer interrupt
	SetBit(TIMSK,0);
	#elif	TIMER0_MODE	==	CTC_MODE
	ClrBit(TCCR0,6);
	SetBit(TCCR0,3);
	//To Enable compare match interrupt
	SetBit(TIMSK,1);
	#endif
	// to enable global int
	SetBit(SREG,7);	
}
void M_Timer0_Timer0SetTime(u32 Local_u32_DesiredTime)
{
	u32	Local_32_TickTime = PRE_SCALER_DF / CRYSTAL_FREQ;
	u32 Local_u32_TotalTicks = ((Local_u32_DesiredTime * 1000)/ Local_32_TickTime);
	#if		TIMER0_MODE	==	NORMAL_MODE	
	Timer0_u32_NumOfOverFlows = Local_u32_TotalTicks /256;
	Timer0_u8_RemTicks = Local_u32_TotalTicks % 256;
	TCNT0              = 256 - Timer0_u8_RemTicks;
	if(Timer0_u8_RemTicks !=0)
	{
		Timer0_u32_NumOfOverFlows++;
	}
	#elif		TIMER0_MODE	==	CTC_MODE
	u32 Local_u32_DivisionFactor = 255;
	while(Local_u32_TotalTicks % Local_u32_DivisionFactor !=0)
	{
		Local_u32_DivisionFactor--;
	}
	Timer0_u32_NumOfCompMatch = Local_u32_TotalTicks / Local_u32_DivisionFactor;
	OCR0	=	Local_u32_DivisionFactor - 1;
	#endif
}

void M_Timer0_Start(void)
{
	#if		PRE_SCALER_DF	==	1024
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif		PRE_SCALER_DF	==	256
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif		PRE_SCALER_DF	==	64
	SetBit(TCCR0,0);
	SetBit(TCCR0,1);
	ClrBit(TCCR0,2);
	#endif
}
void M_Timer0_Stop(void)
{
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	ClrBit(TCCR0,2);
}
void M_Timer0_SetCallBack(void(*Local_void_Ptr)(void))
{
	Timer0_void_CallBack = Local_void_Ptr;
}


void M_Pwm0_Init(void)
{
	SetBit(DDRB,3);   // to make OC0 as output
	// to select fast PWM mode
	SetBit(TCCR0,3);
	SetBit(TCCR0,6);
	#if   FAST_PWM_MOED      ==   NON_INVERTED
	ClrBit(TCCR0,4);
	SetBit(TCCR0,5);
	#elif FAST_PWM_MOED      ==   INVERTED
	SetBit(TCCR0,4);
	SetBit(TCCR0,5);
	#endif
}

void M_Pwm0_SetDutyCycle(u8 Local_u8_DutyCycle)
{
	#if   FAST_PWM_MOED      ==   NON_INVERTED
	OCR0 = (((Local_u8_DutyCycle * 256) / 100) - 1);
	#elif FAST_PWM_MOED      ==   INVERTED
	OCR0 = (255 - ((Local_u8_DutyCycle * 256) / 100));
	#endif
}
void M_Pwm0_Start(void)
{
	M_Timer0_Start();
}
void M_Pwm0_Stop()
{
	M_Timer0_Stop();
}

#if		TIMER0_MODE	==	NORMAL_MODE	
ISR(TIMER0_OVF_vect) 
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if(Local_u32_Counter == Timer0_u32_NumOfOverFlows)
	{
		Timer0_void_CallBack();
		Local_u32_Counter = 0;
		TCNT0             = 256 - Timer0_u8_RemTicks;
	}
}
#elif		TIMER0_MODE	==	CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if(Local_u32_Counter == Timer0_u32_NumOfCompMatch)
	{
		Timer0_void_CallBack();
		Local_u32_Counter = 0;
	}
}
#endif