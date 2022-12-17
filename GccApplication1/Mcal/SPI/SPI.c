/*
 * SPI.c
 *
 * Created: 11/18/2022 9:38:01 PM
 *  Author: Aya Yasser
 */ 

#include "SPI.h"

void M_SPI_SPIInit(void)
{
		#if	 SPI_MODE   ==   SPI_MASTER
		M_DIO_PinMode(MOSI_PIN,OUTPUT);
		M_DIO_PinMode(MISO_PIN,INPUT);
		M_DIO_PinMode(SCK_PIN,OUTPUT);
		M_DIO_PinMode(SS_PIN,OUTPUT);
		
		//To select 128 Division factor
		SetBit(SPCR,0);
		SetBit(SPCR,1);
		
		ClrBit(SPCR,3);		//Select rising edge with leading
		SetBit(SPCR,2);		// to setup(Send) with leading edge
		SetBit(SPCR,4);		// to select Master
		ClrBit(SPCR,5);		// to select MSB as first send bit
		
		#elif	 SPI_MODE   ==   SPI_SLAVE
		M_DIO_PinMode(MOSI_PIN,INPUT);
		M_DIO_PinMode(MISO_PIN,OUTPUT);
		M_DIO_PinMode(SCK_PIN,INPUT);
		M_DIO_PinMode(SS_PIN,INPUT);
		ClrBit(SPCR,4);		// to select Slave
		#endif
		
		SetBit(SPCR,6);		// To enable SPI circuit
}

u8 M_SPI_SPITransive(u8	Local_u8_Data)
{
		SPDR = Local_u8_Data;
		while(GetBit(SPSR,7) == 0);
		return SPDR;
}
