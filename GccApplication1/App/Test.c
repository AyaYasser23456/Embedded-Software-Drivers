/*
 * Test.c
 *
 * Created: 10/21/2022 8:34:17 PM
 *  Author: Aya
 */ 
// #include <avr/io.h>
/***********************StepperMotor_Test_*************************/
/*
	H_StepperMotor_Init();
	H_StepperMotor_Start(5);
*/	
/***********************_EEPROM_Test_*************************/
/*
H_Lcd_LcdInit();
H_EEPROM_Init();
u8 x,page=2,byte_add=150;
x= H_EEPROM_Read(page,byte_add);
H_Lcd_LcdWriteNumber(x); 
*/
/***********************_Bleutooth_Test_*************************/
/*
#include "Led.h"
#include "Bluetooth_HC05.h"
#include "SPI.h"
{
	H_LED_LedInit(Led0);
	H_LED_LedInit(Led1);
	H_LED_LedInit(Led2);
	H_Bluetooth_HC05_Init();
	
	while(1)
	{
		u8 Reading = H_Bluetooth_HC05_Receive();
		if(Reading == 'A')
		H_LED_LedOn(Led0);
		else if(Reading == 'B')
		H_LED_LedOff(Led0);
	}
	return 0;
}
*/
/***********************_WDT_Test_*************************/	

/*
#include "Led.h"
#include "WDT.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	H_LED_LedInit(Led1);
	H_LED_LedInit(Led2);
	_delay_ms(200);
	H_LED_LedOn(Led1);
	M_WDT_Init();
	while(1)
	{
		M_WDT_Reset();
	}
	H_LED_LedTog(Led2);
}
*/
/***********************_Timer0_Test_*************************/	

/*
H_LED_LedInit(Led0);
H_LED_LedInit(Led1);
H_LED_LedOn(Led1);
H_ServoMotor_Init();
H_ServoMotor_SetAngle(0);
_delay_ms(2000);
H_ServoMotor_SetAngle(90);
*/

/***********************_Timer0_Test_*************************/	

/*
#include "Timer0.h"
#include "Led.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void A_Main_Timer0Exc(void);

int main(void)
{
	H_LED_LedInit(Led0);
	H_LED_LedInit(Led1);
	M_Timer0_SetCallBack(A_Main_Timer0Exc);
	M_Timer0_Timer0Init();
	M_Timer0_Timer0SetTime(700);
	M_Timer0_Start();
	H_LED_LedOn(Led0);
	while(1)
	{
		
	}
}

void A_Main_Timer0Exc(void)
{
	H_LED_LedTog(Led1);
}
*/

/***********************_DC_MOTOR_Test_*************************/	
/*

#include "DcMotor.h"
#include "Led.h"
#include "Lcd.h"
#include "Lm35.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	H_LED_LedInit(Led0);
	H_LED_LedInit(Led1);
	H_Lcd_LcdInit();
	H_Lm35_Lm35Int();
	u16 reading = H_Lm35_Lm35Read();
	H_Lcd_LcdWriteNumber(reading);
	H_LED_LedOn(Led1);
	_delay_ms(100);
	H_DcMotor_DcMotorInit();
	H_DcMotor_DcMotorSetDirection(CW);
	H_DcMotor_DcMotorSetSpeed(5);
	H_DcMotor_DcMotorStart();
}
*/

/***********************_ADC & LM35_Test_*************************/	
/*	H_Lcd_LcdInit();
	H_Lm35_Lm35Int();
	H_Lcd_LcdWriteString("Temp= ");
	
	u16 Local_u16_Temp=0;
	while(1)
	{
		Local_u16_Temp = H_Lm35_Lm35Read();
		H_Lcd_LcdGoTo(0,6);
		H_Lcd_LcdWriteNumber((f32)Local_u16_Temp);
		_delay_ms(500);
	}
*/
/***********************_EXT_INT_Test_*************************/	
  /* void A_main_ExtIntExc(void);

  int main(void)
  {
  H_LED_LedInit(Led0);
  H_LED_LedInit(Led1);
  
  M_ExtInt_SetCallBack(A_main_ExtIntExc);
  M_ExtInt_Init();
  while(1)
  {
  H_LED_LedOn(Led1);
  _delay_ms(1000);
  }
  }

  void A_main_ExtIntExc(void)
  {
  H_LED_LedTog(Led0);
  }

*/
/***********************_Keypad_Test_*************************/

	/*H_Ssd_SsdInit();
	while(1)
	{
		H_Ssd_SsdDisplay(27);
	}*/

/***********************_Keypad_Test_*************************/
 
 /*
    H_Lcd_LcdInit();
	H_Keypad_KeypadInit();
	
	H_Lcd_LcdWriteChar('A');
	H_Lcd_LcdWriteChar('1');
	
	u8 Data = 0;
	while (1) 
    {
		Data = H_Keypad_KeypadRead();
		if(Data)
		{
			H_Lcd_LcdWriteChar(Data);
			H_LED_LedOn(Led1);
		}
	}

*/
 
 
 
/*************************_LCD_Test_****************************/
	/*	H_Lcd_LcdWriteString("Aya");
		H_Lcd_LcdGoTo(1,4);
		H_Lcd_LcdWriteNumber(12.45);
		_delay_ms(500);
		H_Lcd_LcdClear();
		_delay_ms(500);
		*/
	
	
	
/*****************_lighting Leds by pushing button_***********/
	
	/* 	u8 Local_u8_Reading = 0;
		Local_u8_Reading = H_PushButton_Read(Button_0);
		if( Local_u8_Reading == PRESSED)
		{
			_delay_ms(80);
			Local_u8_Reading = H_PushButton_Read(Button_0);
			if(Local_u8_Reading == PRESSED)
			{
				while(H_PushButton_Read(Button_0) == PRESSED);
				H_LED_LedOff(Led0);
			}	
		}
		
		Local_u8_Reading = H_PushButton_Read(Button_1);
		if( Local_u8_Reading == PRESSED)
		{
			_delay_ms(80);
			Local_u8_Reading = H_PushButton_Read(Button_1);
			if(Local_u8_Reading == PRESSED)
			{
				while(H_PushButton_Read(Button_1) == PRESSED);
				H_LED_LedOn(Led0);
			}
		}	
		
		Local_u8_Reading = H_PushButton_Read(Button_2);
		if( Local_u8_Reading == PRESSED)
		{
			_delay_ms(80);
			Local_u8_Reading = H_PushButton_Read(Button_2);
			if(Local_u8_Reading == PRESSED)
			{
				while(H_PushButton_Read(Button_2) == PRESSED);
				H_LED_LedTog(Led2);
			}
		}
*/

