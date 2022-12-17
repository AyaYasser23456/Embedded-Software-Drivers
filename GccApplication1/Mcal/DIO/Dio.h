/*
 * IncFile1.h
 *
 * Created: 9/30/2022 5:25:13 PM
 *  Author: compu-johnson
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

/***********************_Includes_***********************/
#include "BitMath.h"
#include "StdTypes.h"
#include "Reg.h"
/***********************_Macros_***********************/

#define INPUT	0
#define OUTPUT	1

#define LOW		0
#define HIGH	1

#define DISABLE		0
#define ENABLE	1

#define PA0		10
#define PA1		11
#define PA2		12
#define PA3		13
#define PA4		14
#define PA5		15
#define PA6		16
#define PA7		17


#define PB0		20
#define PB1		21
#define PB2		22
#define PB3		23
#define PB4		24
#define PB5		25
#define PB6		26
#define PB7		27

#define PC0		30
#define PC1		31
#define PC2		32
#define PC3		33
#define PC4		34
#define PC5		35
#define PC6		36
#define PC7		37

#define PD0		40
#define PD1		41
#define PD2		42
#define PD3		43
#define PD4		44
#define PD5		45
#define PD6		46
#define PD7		47

/***********************_ProtoTypes_***********************/
void M_DIO_PinMode(u8,u8);
void M_DIO_PinWrite(u8,u8);
u8 M_DIO_PinRead(u8);
void M_DIO_PinTog(u8);
void M_DIO_PinPullUp(u8,u8);

#endif /* INCFILE1_H_ */