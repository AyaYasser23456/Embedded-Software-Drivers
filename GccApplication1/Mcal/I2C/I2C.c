/*
 * I2C.c
 *
 * Created: 12/3/2022 4:36:12 PM
 *  Author: Aya Yasser
 */ 
#include "I2C.h"

void M_I2C_Init(void)
{
	#if		I2C_MODE	==		MASTER_MODE
	TWBR = 12;          // to make Fscl = 400 Khz
	ClrBit(TWSR,0);		// to set TWPS0
	ClrBit(TWSR,1);		// to set TWPS1
	#elif		I2C_MODE	==		SLAVE_MODE
	TWAR = ((SLAVE_ADDRESS << 1) | GENERAL_CALL_MODE)
	#endif
	SetBit(TWCR,2);		// to enable I2C circuit
	_delay_ms(10);
}
void M_I2C_StartCondition(void)
{
	ClrBit(TWCR,4);
	SetBit(TWCR,5);
	SetBit(TWCR,7);
	while((GetBit(TWCR,7)) == 0);
	while((TWSR & 0xF8) != START_CONDITION_TRANSMITTED);
	_delay_ms(10);
}

void M_I2C_SendSLA_W(u8	Local_u8_SlaveAddress)
{
	TWDR = (Local_u8_SlaveAddress << 1);
	SetBit(TWCR,7);
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_WR_ACK);
	_delay_ms(10);
}
void M_I2C_SendSLA_R(u8 Local_u8_SlaveAddress)
{
	TWDR = ((Local_u8_SlaveAddress << 1) | 1);
	SetBit(TWCR,7);
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
	_delay_ms(10);
}
void M_I2C_SendByte(u8 Local_u8_byte)
{
	TWDR = Local_u8_byte;
	ClrBit(TWCR,5);					
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != WR_BYTE_ACK);
	_delay_ms(100);		
}
u8 M_I2C_RecieveByte(void)
{	
	SetBit(TWCR,6);	
	SetBit(TWCR,6);				   	 // to enable send ACK
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	return TWDR;
}

u8 M_I2C_RecieveByte_NoAck(void)
{
	ClrBit(TWCR,6);				   	 // to Disable send ACK
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	return TWDR;
}
void M_I2C_StopCondition(void)
{
	SetBit(TWCR,2);
	SetBit(TWCR,4);				
	ClrBit(TWCR,5);				   	 
	SetBit(TWCR,7);
	_delay_ms(1);
}
void M_I2C_RepeatedStartCondition(void)
{
	SetBit(TWCR,5);
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != REP_START_ACK);
}