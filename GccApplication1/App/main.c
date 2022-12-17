/*
 * GccApplication1.c
 *
 * Created: 9/30/2022 3:34:58 PM
 * Author : Aya
 */ 

#include "StepperMotor.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	H_StepperMotor_Init();
	H_StepperMotor_Start(5);
	while(1)
	{
	
	}
	return 0; 
}
