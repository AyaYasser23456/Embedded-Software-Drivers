/*
 * Keypad.c
 *
 * Created: 10/4/2022 4:18:24 PM
 *  Author: Aya
 */ 

#include "Keypad.h"

void H_Keypad_KeypadInit(void)
{
	M_DIO_PinMode(Keypad_Row_1,OUTPUT);
	M_DIO_PinMode(Keypad_Row_2,OUTPUT);
	M_DIO_PinMode(Keypad_Row_3,OUTPUT);
	M_DIO_PinMode(Keypad_Row_4,OUTPUT);
	
	M_DIO_PinMode(Keypad_Col_1,INPUT);
	M_DIO_PinMode(Keypad_Col_2,INPUT);
	M_DIO_PinMode(Keypad_Col_3,INPUT);
	M_DIO_PinMode(Keypad_Col_4,INPUT);
	
	M_DIO_PinPullUp(Keypad_Col_1,ENABLE);
	M_DIO_PinPullUp(Keypad_Col_2,ENABLE);
	M_DIO_PinPullUp(Keypad_Col_3,ENABLE);
	M_DIO_PinPullUp(Keypad_Col_4,ENABLE);
	
	M_DIO_PinWrite(Keypad_Row_1,HIGH);
	M_DIO_PinWrite(Keypad_Row_2,HIGH);
	M_DIO_PinWrite(Keypad_Row_3,HIGH);
	M_DIO_PinWrite(Keypad_Row_4,HIGH);
	
}

u8 H_Keypad_KeypadRead(void)
{
	u8 Local_u8_KeypadRead = 0;
	u8 Local_u8_KeypadData = 0;
	u8 Local_u8_Keypad_Arr[4][4] = { {'1','2','3','A'},
									 {'4','5','6','B'},
									 {'7','8','9','C'},	 
								   	 {'*','0','#','D'}};
	u8 Local_u8_Keypad_Row = 0;
	u8 Local_u8_Keypad_Col = 0;
	
	for(Local_u8_Keypad_Row =Keypad_Row_1; Local_u8_Keypad_Row <= Keypad_Row_4; Local_u8_Keypad_Row++)
	{
		M_DIO_PinWrite(Local_u8_Keypad_Row,LOW);
		for(Local_u8_Keypad_Col = Keypad_Col_1; Local_u8_Keypad_Col <= Keypad_Col_4; Local_u8_Keypad_Col++)
		{
			Local_u8_KeypadRead = M_DIO_PinRead(Local_u8_Keypad_Col);
			if(Local_u8_KeypadRead == 0)
			{	
				_delay_ms(100);
				if(M_DIO_PinRead(Local_u8_Keypad_Col) == 0)
				{	
					while(M_DIO_PinRead(Local_u8_Keypad_Col) == 0);
					Local_u8_KeypadData = Local_u8_Keypad_Arr[Local_u8_Keypad_Row-Keypad_Row_1][Local_u8_Keypad_Col-Keypad_Col_1];
				}
			}
		}
		M_DIO_PinWrite(Local_u8_Keypad_Row,HIGH);
	}
	return Local_u8_KeypadData;
}