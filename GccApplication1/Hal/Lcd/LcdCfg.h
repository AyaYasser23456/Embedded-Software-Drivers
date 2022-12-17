/*
 * LcdCfg.h
 *
 * Created: 10/8/2022 5:29:49 PM
 *  Author: Aya
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_

/***********************_Macros_***********************/

/******************_LCD_MOED_***************/
// Option_1	->	_4_Bit_Mode
// Option_2	->	_8_Bit_Mode
#define LCD_MOED	_4_Bit_Mode

/******************_LCD_PINs_***************/
#define LCD_DATA_PORT	PORTA

#define LCD_D0	PA0
#define LCD_D1	PA1
#define LCD_D2	PA2
#define LCD_D3	PA3
#define LCD_D4	PA4
#define LCD_D5	PA5
#define LCD_D6	PA6
#define LCD_D7	PA7

#define LCD_RS	PB1
#define LCD_RW	PB2
#define LCD_EN	PB3

#endif /* LCDCFG_H_ */