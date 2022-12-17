/*
 * Led.h
 *
 * Created: 9/30/2022 7:56:46 PM
 *  Author: Aya
 */ 


#ifndef LED_H_
#define LED_H_

/***********************_Includes_***********************/
#include "LedCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include "util/delay.h"
/***********************_Macros_***********************/

#define ON	1
#define OFF 0
/***********************_ProtoTypes_***********************/
void H_LED_LedInit(u8);
void H_LED_LedOn(u8);
void H_LED_LedOff(u8);
void H_LED_LedTog(u8);
void H_LED_LedBlank(u8);

#endif /* LED_H_ */