/*
 * BushButton.h
 *
 * Created: 9/30/2022 7:04:24 PM
 *  Author: Aya
 */ 


#ifndef BUSHBUTTON_H_
#define BUSHBUTTON_H_

/***********************_Includes_***********************/
#include "Dio.h"
#include "PushButtonCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"
/***********************_Macros_***********************/
#define PRESSED			1
#define RELEASED		0

/***********************_ProtoTypes_***********************/
void H_PushButton_Init(u8);
u8 H_PushButton_Read(u8);




#endif /* BUSHBUTTON_H_ */