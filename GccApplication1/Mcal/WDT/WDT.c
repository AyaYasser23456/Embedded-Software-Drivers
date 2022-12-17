/*
 * WDT.c
 *
 * Created: 11/5/2022 3:34:00 AM
 *  Author: compu-johnson
 */ 
#include "WDT.h"
void M_WDT_Init(void)
{
	SetBit(WDTCR,3); // To enable WDT  
	// to choose prescaler timeout 2.1s
	SetBit(WDTCR,0);
	SetBit(WDTCR,1);
	SetBit(WDTCR,2);
}
void M_WDT_Reset(void)
{
	asm("WDR");
}