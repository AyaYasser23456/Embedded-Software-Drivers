/*
 * UART.h
 *
 * Created: 11/12/2022 2:54:56 PM
 *  Author: Aya Yasser
 */ 


#ifndef UART_H_
#define UART_H_

/*********************************_INCLUDES_******************************/
#include "UARTCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"

/***********************************_MACOS_*******************************/
#define EVEN	2
#define ODD		1
#define PARTY_DISABLE	0
/********************************_PROTOTYPES_*****************************/

void M_UART_UARTInit(void);
void M_UART_UARTWrite(u8);
u8 M_UART_UARTRead(void);

#endif /* UART_H_ */