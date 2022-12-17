/*
 * Lcd.c
 *
 * Created: 10/8/2022 5:29:20 PM
 *  Author: Aya
 */ 

#include "Lcd.h"

void H_Lcd_LcdInit(void)
{
	#if LCD_MOED	==	_8_Bit_Mode
	M_DIO_PinMode(LCD_D0,OUTPUT);
	M_DIO_PinMode(LCD_D1,OUTPUT);
	M_DIO_PinMode(LCD_D2,OUTPUT);
	M_DIO_PinMode(LCD_D3,OUTPUT);
	M_DIO_PinMode(LCD_D4,OUTPUT);
	M_DIO_PinMode(LCD_D5,OUTPUT);
	M_DIO_PinMode(LCD_D6,OUTPUT);
	M_DIO_PinMode(LCD_D7,OUTPUT);
	
	M_DIO_PinMode(LCD_RS,OUTPUT);
	M_DIO_PinMode(LCD_RW,OUTPUT);
	M_DIO_PinMode(LCD_EN,OUTPUT);
	_delay_ms(1000);
	H_Lcd_LcdWriteCmd(0x38);	//Acive 8-bit Mode
	H_Lcd_LcdWriteCmd(0x01);	//Clear Screen
	H_Lcd_LcdWriteCmd(0x0C);	//Display ON, cursor OFF
	H_Lcd_LcdWriteCmd(0x02);	//Return Home
	
	#elif	LCD_MOED	==	_4_Bit_Mode
	M_DIO_PinMode(LCD_D4,OUTPUT);
	M_DIO_PinMode(LCD_D5,OUTPUT);
	M_DIO_PinMode(LCD_D6,OUTPUT);
	M_DIO_PinMode(LCD_D7,OUTPUT);
	
	M_DIO_PinMode(LCD_RS,OUTPUT);
	M_DIO_PinMode(LCD_RW,OUTPUT);
	M_DIO_PinMode(LCD_EN,OUTPUT);
	
	_delay_ms(1000);
	H_Lcd_LcdWriteCmd(0x33);	//Acive 4-bit Mode
	H_Lcd_LcdWriteCmd(0x32);	//Acive 4-bit Mode
	H_Lcd_LcdWriteCmd(0x28);	//Acive 4-bit Mode
	H_Lcd_LcdWriteCmd(0x01);	//Clear Screen
	H_Lcd_LcdWriteCmd(0x0C);	//Display ON, cursor OFF
	H_Lcd_LcdWriteCmd(0x02);	//Return Home
	#endif	
}

void H_Lcd_LcdWriteCmd(u8 Local_u8_Cmd)
{
	#if		LCD_MOED	==	_8_Bit_Mode
	M_DIO_PinWrite(LCD_RS,LOW);
	LCD_DATA_PORT = Local_u8_Cmd;
	M_DIO_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_DIO_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	
	#elif	LCD_MOED	==	_4_Bit_Mode
	M_DIO_PinWrite(LCD_RS,LOW);
	LCD_DATA_PORT = ((LCD_DATA_PORT & 0x0F) | (Local_u8_Cmd & 0xF0));
	M_DIO_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_DIO_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = ((LCD_DATA_PORT & 0x0F) | ((Local_u8_Cmd << 4)));
	M_DIO_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_DIO_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	#endif
}

void H_Lcd_LcdWriteChar(u8 Local_u8_char)
{
	#if		LCD_MOED	==	_8_Bit_Mode
	M_DIO_PinWrite(LCD_RS,HIGH);
	LCD_DATA_PORT = Local_u8_char;
	M_DIO_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_DIO_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	
	#elif	LCD_MOED	==	_4_Bit_Mode
	M_DIO_PinWrite(LCD_RS,HIGH);
	LCD_DATA_PORT = ((LCD_DATA_PORT & 0x0F) | (Local_u8_char & 0xF0));
	M_DIO_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_DIO_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	LCD_DATA_PORT = ((LCD_DATA_PORT & 0x0F) | ((Local_u8_char << 4)));
	M_DIO_PinWrite(LCD_EN,HIGH);
	_delay_ms(1);
	M_DIO_PinWrite(LCD_EN,LOW);
	_delay_ms(5);
	#endif
}

void H_Lcd_LcdWriteNumber(f32 Local_f32_Number)
{
	if(Local_f32_Number == 0)
	{
		H_Lcd_LcdWriteChar('0');
	}
	
	if(Local_f32_Number < 0)
	{
		H_Lcd_LcdWriteChar('-');
		Local_f32_Number =Local_f32_Number * -1;
	}

	if(Local_f32_Number > 0)
	{
		u8 Local_u8_Arr[10]={0};	// Unsigned integer max digit is 10;
		s8 Local_s8_Counter=0;
		u32 Local_u32_IntNumber = Local_f32_Number ;
		u8 Local_u8_Decimal_Pos = -1;
		while((Local_f32_Number - Local_u32_IntNumber) > 0)
		{
			Local_f32_Number *= 10.0;
			Local_u32_IntNumber=Local_f32_Number;
			Local_u8_Decimal_Pos++;
		}
		while(Local_u32_IntNumber != 0){
			Local_u8_Arr[Local_s8_Counter] = (Local_u32_IntNumber%10);
			Local_s8_Counter++;
			Local_u32_IntNumber = Local_u32_IntNumber / 10;
		}
		Local_s8_Counter--;
		while(Local_s8_Counter>-1)
		{
			if((Local_u8_Decimal_Pos !=-1) && (Local_s8_Counter == Local_u8_Decimal_Pos))
			{
				H_Lcd_LcdWriteChar('.');
			}
			H_Lcd_LcdWriteChar(Local_u8_Arr[Local_s8_Counter]+48);	// Ascii =Num + 48
			Local_s8_Counter--;
		}
	}
	
}

void H_Lcd_LcdWriteString(u8* Local_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8_Ptr[Local_u8_Counter] != '\0')
	{
		H_Lcd_LcdWriteChar(Local_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}

void H_Lcd_LcdGoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_arr[2]={0x80,0xC0};
	H_Lcd_LcdWriteCmd(Local_u8_arr[Local_u8_Row]+Local_u8_Col);
}

void H_Lcd_LcdClear()
{
	H_Lcd_LcdWriteCmd(0x01);
}