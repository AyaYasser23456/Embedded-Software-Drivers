/*
 * Timer0Cfg.h
 *
 * Created: 10/22/2022 2:46:11 PM
 *  Author: Aya
 */ 


#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_

/*******************************_SELECT_CRYSTAL_FREQ_******************************/
// note -> Enter the crystal freq. value without zeros
#define CRYSTAL_FREQ      16
/*******************************_SELECT_PRE_SCALER_DF_******************************/
/*option 1 -> [ 1024 ] */
/*option 2 -> [ 256  ] */
/*option 3 -> [ 64   ] */
#define PRE_SCALER_DF    1024
/******************_TIMER_MOED_***************/
// Option_1	->		NORMAL_MODE
// Option_2	->		PWM_PHASE_CORRECT
// Option_3	->		CTC_MODE
// Option_4	->		FAST_PWM
#define	TIMER0_MODE	CTC_MODE	

/******************_FAST_PWM_MOED_***************/
// Option_1	->		INVERTED
// Option_2	->		NON_INVERTED
// Option_3	->		REVERSED
#define FAST_PWM_MOED	NON_INVERTED

#endif /* TIMER0CFG_H_ */