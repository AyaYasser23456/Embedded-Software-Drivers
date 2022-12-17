/*
 * StepperMotor.h
 *
 * Created: 12/10/2022 2:13:06 AM
 *  Author: Aya Yasser
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

/*********************************_INCLUDES_******************************/
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"
#include "StepperMotorCfg.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/***********************************_MACOS_*******************************/

/********************************_PROTOTYPES_*****************************/

void H_StepperMotor_Init(void);
void H_StepperMotor_Start(u16);

#endif /* STEPPERMOTOR_H_ */