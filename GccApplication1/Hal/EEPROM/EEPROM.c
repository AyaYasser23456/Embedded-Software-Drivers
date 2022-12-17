/*
 * EEPROM.c
 *
 * Created: 12/3/2022 9:20:02 PM
 *  Author: Aya Yasser
 */ 

#include "EEPROM.h"

void H_EEPROM_Init(void)
{
	M_I2C_Init();
}
u8 H_EEPROM_Read(u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	u8 Local_u8_Data = 0;
	M_I2C_StartCondition();
	M_I2C_SendSLA_W((0x50 | Local_u8_PageAddress));
	M_I2C_SendByte(Local_u8_ByteAddress);
	M_I2C_RepeatedStartCondition();
	M_I2C_SendSLA_R((0x50 | Local_u8_PageAddress));
	Local_u8_Data = M_I2C_RecieveByte_NoAck();
	M_I2C_StopCondition();
	return Local_u8_Data;
}
void H_EEPROM_Write(u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress,u8 Local_u8_Data)
{
	if(Local_u8_PageAddress < 8)
	{
		M_I2C_StartCondition();
		M_I2C_SendSLA_W((0x50 | Local_u8_PageAddress));
		M_I2C_SendByte(Local_u8_ByteAddress);
		M_I2C_SendByte(Local_u8_Data);
		M_I2C_StopCondition();	
	}
}