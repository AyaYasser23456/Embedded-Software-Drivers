/*
 * Servo.h
 *
 * Created: 11/5/2022 12:40:41 AM
 *  Author: Aya Yasser
 */ 


#ifndef SERVO_H_
#define SERVO_H_

/*********************************_INCLUDES_******************************/
//#include <avr/interrupt.h>
#include "StdTypes.h"
#include "Reg.h"
#include "Dio.h"
#include "ServoCfg.h"
#include "Timer1.h"
/***********************************_MACROS_******************************/

/********************************_PROTO_TYPES_****************************/
void H_ServoMotor_Init(void);
/*To set angel, Enter your desired angel from 0 to 180*/ 
void H_ServoMotor_SetAngle(f32);
void H_ServoMotor_TurnOff(void);

#endif /* SERVO_H_ */