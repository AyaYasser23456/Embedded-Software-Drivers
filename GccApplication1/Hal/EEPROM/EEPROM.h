/*
 * EEPROM.h
 *
 * Created: 12/3/2022 9:20:18 PM
 *  Author: Aya Yasser
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

/*********************************_INCLUDES_******************************/
#include "I2C.h"
#include "EEPROMCfg.h"
/***********************************_MACOS_*******************************/

/********************************_PROTOTYPES_*****************************/
void H_EEPROM_Init(void);
u8 H_EEPROM_Read(u8,u8);
void H_EEPROM_Write(u8,u8,u8);
#endif /* EEPROM_H_ */