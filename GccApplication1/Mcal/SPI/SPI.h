/*
 * SPI.h
 *
 * Created: 11/18/2022 9:37:27 PM
 *  Author: Aya Yasser
 */ 


#ifndef SPI_H_
#define SPI_H_

/*********************************_INCLUDES_******************************/
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"
#include "SPICfg.h"
/***********************************_MACOS_*******************************/
#define SPI_MASTER		0
#define SPI_SLAVE		1

/********************************_PROTOTYPES_*****************************/
void M_SPI_SPIInit(void);
u8 M_SPI_SPITransive(u8);

#endif /* SPI_H_ */