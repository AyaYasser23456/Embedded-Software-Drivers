/*
 * DcMotor.c
 *
 * Created: 10/28/2022 9:32:25 PM
 *  Author: Aya Yasser
 */ 
#include "DcMotor.h"

void H_DcMotor_DcMotorInit(void)
{
	M_DIO_PinMode(DCMOTOR_PIN_1,OUTPUT);
	M_DIO_PinMode(DCMOTOR_PIN_2,OUTPUT);	
	M_Pwm2_Init();
}

void H_DcMotor_DcMotorSetDirection(u8 Local_u8_Direction)
{
	switch(Local_u8_Direction)
	{
		case CW:
			M_DIO_PinWrite(DCMOTOR_PIN_1,HIGH);
			M_DIO_PinWrite(DCMOTOR_PIN_2,LOW);
		break;
		case ACW:
			M_DIO_PinWrite(DCMOTOR_PIN_2,HIGH);
			M_DIO_PinWrite(DCMOTOR_PIN_1,LOW);
		break;
		default:							break;
	}
}

void H_DcMotor_DcMotorSetSpeed(u8 Local_u8_Speed)
{
	//Speed range [0-100]
	M_Pwm2_SetDutyCycle(Local_u8_Speed);
}

void H_DcMotor_DcMotorStart(void)
{
	M_Pwm2_Start();
}
void H_DcMotor_DcMotorStop(void)
{
	M_Pwm2_Stop();
}