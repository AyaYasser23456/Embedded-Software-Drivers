/*
 * Keypad.h
 *
 * Created: 10/4/2022 4:18:45 PM
 *  Author: Aya
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/***********************_Includes_***********************/
#include "Dio.h"
#include "KeypadCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"
/***********************_Macros_***********************/
#define TYPE_1	1
#define TYPE_2	2
/***********************_ProtoTypes_***********************/

void H_Keypad_KeypadInit(void);
u8 H_Keypad_KeypadRead(void);


#endif /* KEYPAD_H_ */