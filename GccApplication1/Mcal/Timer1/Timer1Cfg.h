/*
 * Timer1Cfg.h
 *
 * Created: 10/28/2022 11:25:03 PM
 *  Author: Aya Yasser
 */ 


#ifndef TIMER1CFG_H_
#define TIMER1CFG_H_

/*******************************_SELECT_CRYSTAL_FREQ_******************************/
// note -> Enter the crystal freq. value without zeros
#define CRYSTAL_FREQ      16
/*******************************_SELECT_PRE_SCALER_DF_******************************/
/*option 1 -> [ 1024 ] */
/*option 2 -> [ 256  ] */
/*option 3 -> [ 64   ] */
#define Timer1_PRE_SCALER_DF    64



#endif /* TIMER1CFG_H_ */