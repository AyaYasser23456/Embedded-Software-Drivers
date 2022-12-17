/*
 * ADC.h
 *
 * Created: 10/21/2022 10:09:48 PM
 *  Author: Aya
 */ 


#ifndef ADC_H_
#define ADC_H_

/*********************************_INCLUDES_******************************/
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "ADCCfg.h"
//#include <avr/interrupt.h>
/***********************************_MACOS_*******************************/
#define	AREF			1
#define	AVCC			2
#define	Reserved		3
#define	Int_2V56		4
#define	_32				1
#define	_64				2
#define	_128			3

#define	LEFT_ADJUST		1
#define	RIGHT_ADJUST	2

#define	ADC0			0
#define	ADC1			1
#define	ADC2			2
#define	ADC3			3
#define	ADC4			4
#define	ADC5			5
#define	ADC6			6
#define	ADC7			7	
/********************************_PROTOTYPES_*****************************/

void M_ADC_ADCInt(u8);
u16 M_ADC_ADCRead(void);

#endif /* ADC_H_ */