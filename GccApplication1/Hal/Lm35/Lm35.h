/*
 * Lm35.h
 *
 * Created: 10/22/2022 12:18:22 AM
 *  Author: Aya
 */ 


#ifndef LM35_H_
#define LM35_H_

/*********************************_INCLUDES_******************************/
#include "ADC.h"
#include "Lm35Cfg.h"
/***********************************_MACOS_*******************************/

/********************************_PROTOTYPES_*****************************/

void H_Lm35_Lm35Int(void);
f32 H_Lm35_Lm35Read(void);

#endif /* LM35_H_ */