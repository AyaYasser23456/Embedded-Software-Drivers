/*
 * ExtInt.h
 *
 * Created: 10/14/2022 9:45:34 PM
 *  Author: Aya
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

/*********************************_INCLUDES_******************************/
#include <avr/interrupt.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "ExtIntCfg.h"
/***********************************_MACOS_*******************************/
#define		RISING_EDGE		1
#define		FALLING_EDGE	2
#define		ANY_L_CHENGE	3
#define		LOW_LEVEL		4
#define		NULL_			'\0'


/********************************_PROTOTYPES_*****************************/
void M_ExtInt_Init(void);
void M_ExtInt_SetCallBack(void (*)(void));

#endif /* EXTINT_H_ */