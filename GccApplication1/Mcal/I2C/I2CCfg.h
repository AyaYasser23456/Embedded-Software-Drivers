/*
 * I2CCfg.h
 *
 * Created: 12/3/2022 4:37:19 PM
 *  Author: Aya Yasser
 */ 


#ifndef I2CCFG_H_
#define I2CCFG_H_

/********************************_SELECT_SLAVE_ADDRESS_*****************************/
#define SLAVE_ADDRESS        1
/****************************************_I2C_MODE_*********************************/

// OPTION 1  ->  MASTER_MODE 
// OPTION 2  ->  SLAVE_MODE
#define I2C_MODE	MASTER_MODE

/************************************_GENERAL_CALL_MODE_*****************************/

// OPTION 1  ->  EN_GC
// OPTION 2  ->  DIS_GC
#define GENERAL_CALL_MODE	EN_GC

#endif /* I2CCFG_H_ */