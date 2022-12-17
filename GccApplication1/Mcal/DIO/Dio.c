/*
 * Dio.c
 *
 * Created: 9/30/2022 5:26:27 PM
 *  Author: Aya
 */ 

#include "Dio.h"

void M_DIO_PinMode(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	u8 Local_u8_Pin = Local_u8_Num % 10 ;
	u8 Local_u8_Port = Local_u8_Num / 10 ;
	
	switch(Local_u8_Mode)
	{
		case  INPUT:
			switch(Local_u8_Port)
			{
				case 1 :	ClrBit(DDRA,Local_u8_Pin);	break;
				case 2 :	ClrBit(DDRB,Local_u8_Pin);	break;
				case 3 :	ClrBit(DDRC,Local_u8_Pin);	break;
				case 4 :	ClrBit(DDRD,Local_u8_Pin);	break;
				default:								break;
			}
			break;
		case  OUTPUT:
		switch(Local_u8_Port)
		{
			case 1 :	SetBit(DDRA,Local_u8_Pin);	break;
			case 2 :	SetBit(DDRB,Local_u8_Pin);	break;
			case 3 :	SetBit(DDRC,Local_u8_Pin);	break;
			case 4 :	SetBit(DDRD,Local_u8_Pin);	break;
			default:								break;
		}	
		break;
		default:
		break;
	}
}

void M_DIO_PinWrite(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	u8 Local_u8_Pin = Local_u8_Num % 10 ;
	u8 Local_u8_Port = Local_u8_Num / 10 ;
	
	switch(Local_u8_Mode)
	{
		case  LOW:
		switch(Local_u8_Port)
		{
			case 1 :	ClrBit(PORTA,Local_u8_Pin);	break;
			case 2 :	ClrBit(PORTB,Local_u8_Pin);	break;
			case 3 :	ClrBit(PORTC,Local_u8_Pin);	break;
			case 4 :	ClrBit(PORTD,Local_u8_Pin);	break;
			default:								break;
		}
		break;
		case  HIGH:
		switch(Local_u8_Port)
		{
			case 1 :	SetBit(PORTA,Local_u8_Pin);	break;
			case 2 :	SetBit(PORTB,Local_u8_Pin);	break;
			case 3 :	SetBit(PORTC,Local_u8_Pin);	break;
			case 4 :	SetBit(PORTD,Local_u8_Pin);	break;
			default:								break;
		}
		break;
		default:
		break;
	}
}

void M_DIO_PinTog(u8 Local_u8_Num)
{
	u8 Local_u8_Pin = Local_u8_Num % 10 ;
	u8 Local_u8_Port = Local_u8_Num / 10 ;
	
	switch(Local_u8_Port)
	{
		case 1 :	TogBit(PORTA,Local_u8_Pin);	break;
		case 2 :	TogBit(PORTB,Local_u8_Pin);	break;
		case 3 :	TogBit(PORTC,Local_u8_Pin);	break;
		case 4 :	TogBit(PORTD,Local_u8_Pin);	break;
		default:								break;
	}
}

u8 M_DIO_PinRead(u8 Local_u8_Num)
{
	u8 Local_u8_Pin = Local_u8_Num % 10 ;
	u8 Local_u8_Port = Local_u8_Num / 10 ;
	u8 Local_u8_Reading = 0;
	switch(Local_u8_Port)
	{
		case 1 :	Local_u8_Reading = GetBit(PINA,Local_u8_Pin);	break;
		case 2 :	Local_u8_Reading = GetBit(PINB,Local_u8_Pin);	break;
		case 3 :	Local_u8_Reading = GetBit(PINC,Local_u8_Pin);	break;
		case 4 :	Local_u8_Reading = GetBit(PIND,Local_u8_Pin);	break;
		default:								break;
	}	
	return Local_u8_Reading;
}

void M_DIO_PinPullUp(u8 Local_u8_Num,u8 Local_u8_Mode)
{
		u8 Local_u8_Pin = Local_u8_Num % 10 ;
		u8 Local_u8_Port = Local_u8_Num / 10 ;
		
		switch(Local_u8_Mode)
		{
			case  DISABLE:
			switch(Local_u8_Port)
			{
				case 1 :	ClrBit(PORTA,Local_u8_Pin);	break;
				case 2 :	ClrBit(PORTB,Local_u8_Pin);	break;
				case 3 :	ClrBit(PORTC,Local_u8_Pin);	break;
				case 4 :	ClrBit(PORTD,Local_u8_Pin);	break;
				default:								break;
			}
			break;
			case  ENABLE:
			switch(Local_u8_Port)
			{
				case 1 :	SetBit(PORTA,Local_u8_Pin);	break;
				case 2 :	SetBit(PORTB,Local_u8_Pin);	break;
				case 3 :	SetBit(PORTC,Local_u8_Pin);	break;
				case 4 :	SetBit(PORTD,Local_u8_Pin);	break;
				default:								break;
			}
			break;
			default:
			break;
		}
}