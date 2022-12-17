/*
 * Ssd.h
 *
 * Created: Aya
 */ 


#ifndef SSD_H_
#define SSD_H_

/***********************_Includes_***********************/
#include "Dio.h"
#include "SsdCfg.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "StdTypes.h"
#include "BitMath.h"
/***********************_Macros_***********************/

/***********************_ProtoTypes_***********************/
void H_Ssd_SsdInit(void);
void H_Ssd_SsdDisplay(u8);

#endif /* SSD_H_ */