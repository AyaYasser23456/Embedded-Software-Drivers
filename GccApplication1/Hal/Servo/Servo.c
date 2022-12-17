/*
 * Servo.c
 *
 * Created: 11/5/2022 12:40:29 AM
 *  Author: Aya Yasser
 */ 
#include "Servo.h"

void H_ServoMotor_Init(void)
{
	M_DIO_PinMode(Servo_Motor_PIN,OUTPUT);
	M_Pwm1_Init();
	M_Pwm1_SetPwmFrequancy(50);	
}

//To set angel, Enter your desired angel from 0 to 180
//To set desired angel for the servo step, Servo usually works from 5% to 10% duty cycle so I mapped 0-180 degrees to 5%-10% 
void H_ServoMotor_SetAngle(f32 Local_f32_Angle)
{
	f32 Local_Servo_Dutycycle = (Local_f32_Angle / 36.0) + 5;
	M_Pwm1_SetDutyCycle(Local_Servo_Dutycycle);	
	M_Pwm1_Start();	
}
void H_ServoMotor_TurnOff(void)
{
	M_Pwm1_Stop();	
}