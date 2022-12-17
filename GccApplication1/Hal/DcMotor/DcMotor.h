/*
 * DcMotor.h
 *
 * Created: 10/28/2022 9:32:36 PM
 *  Author: Aya Yasser
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/***********************_Includes_***********************/
#include "DcMotorCfg.h"
#include "Timer2.h"
#include "StdTypes.h"
#include "Reg.h"
#include "Dio.h"
/***********************_Macros_***********************/
#define CW	1
#define ACW	2
/***********************_ProtoTypes_***********************/
void H_DcMotor_DcMotorInit(void);
void H_DcMotor_DcMotorSetDirection(u8);
void H_DcMotor_DcMotorSetSpeed(u8);
void H_DcMotor_DcMotorStart(void);
void H_DcMotor_DcMotorStop(void);

#endif /* DCMOTOR_H_ */