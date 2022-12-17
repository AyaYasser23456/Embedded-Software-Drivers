/*
 * SPICfg.h
 *
 * Created: 11/18/2022 9:37:44 PM
 *  Author: Aya Yasser
 */ 


#ifndef SPICFG_H_
#define SPICFG_H_

/****************************************_SPI_PINs_*********************************/
#define SS_PIN		PB4
#define MOSI_PIN	PB5
#define MISO_PIN	PB6
#define SCK_PIN		PB7

/***********************************_SELECT_SPI_MODE_*******************************/
// option 1 -> [ SPI_MASTER ]
// option 2 -> [ SPI_SLAVE  ]

#define SPI_MODE                        SPI_MASTER

#endif /* SPICFG_H_ */