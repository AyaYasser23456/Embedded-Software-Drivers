/*
 * Lcd.h
 *
 * Created: 10/8/2022 5:29:34 PM
 *  Author: Aya
 */ 


#ifndef LCD_H_
#define LCD_H_

/***********************_Includes_***********************/
#include "Dio.h"
#include "LcdCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "StdTypes.h"
#include "BitMath.h"
/***********************_Macros_***********************/
#define _4_Bit_Mode	1
#define _8_Bit_Mode	2
/***********************_ProtoTypes_***********************/

void H_Lcd_LcdInit(void);
void H_Lcd_LcdWriteCmd(u8);
void H_Lcd_LcdWriteChar(u8);
void H_Lcd_LcdWriteNumber(f32);
void H_Lcd_LcdWriteString(u8*);
void H_Lcd_LcdGoTo(u8,u8);
void H_Lcd_LcdClear(void);

#endif /* LCD_H_ */