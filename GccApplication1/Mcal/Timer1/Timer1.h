/*
 * Timer1.h
 *
 * Created: 10/28/2022 11:24:51 PM
 *  Author: Aya Yasser
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

/*********************************_INCLUDES_******************************/
//#include <avr/interrupt.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "Timer1Cfg.h"
#include <avr/interrupt.h>
/********************************_PROTO_TYPES_****************************/
void M_Pwm1_Init(void);
void M_Pwm1_SetDutyCycle(f32);
void M_Pwm1_SetPwmFrequancy(u16);
void M_Pwm1_Start(void);
void M_Pwm1_Stop(void);
#endif /* TIMER1_H_ */