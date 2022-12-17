/*
 * Bluetooth_HC05.h
 *
 * Created: 11/12/2022 5:16:10 PM
 *  Author: Aya Yasser
 */ 


#ifndef BLUETOOTH_HC05_H_
#define BLUETOOTH_HC05_H_

/*********************************_INCLUDES_******************************/
#include "Bluetooth_HC05Cfg.h"
#include "UART.h"
/***********************************_MACOS_*******************************/

/********************************_PROTOTYPES_*****************************/
void H_Bluetooth_HC05_Init();
void H_Bluetooth_HC05_Send(u8);
u8 H_Bluetooth_HC05_Receive();

#endif /* BLUETOOTH_HC05_H_ */