/*
 * Timer0.h
 *
 * Created: 10/22/2022 2:45:53 PM
 *  Author: Aya
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/*********************************_INCLUDES_******************************/
//#include <avr/interrupt.h>
#include "Timer0Cfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include <avr/interrupt.h>
/***********************************_MACOS_*******************************/
#define	NORMAL_MODE			1
#define	PWM_PHASE_CORRECT	2
#define	CTC_MODE			3
#define	FAST_PWM			4
#define	INVERTED			1
#define	NON_INVERTED		2
#define NULL_				'\0'
/********************************_PROTOTYPES_*****************************/
void M_Timer0_Timer0Init(void);
void M_Timer0_Timer0SetTime(u32);
void M_Timer0_Start(void);
void M_Timer0_Stop(void);
void M_Timer0_SetCallBack(void(*)(void));

void M_Pwm0_Init(void);
void M_Pwm0_SetDutyCycle(u8);
void M_Pwm0_Start(void);
void M_Pwm0_Stop(void);
#endif /* TIMER0_H_ */