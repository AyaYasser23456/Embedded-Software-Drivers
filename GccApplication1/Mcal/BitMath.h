/*
 * BitMath.h
 *
 * Created: 9/30/2022 5:11:55 PM
 *  Author: Aya
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(REG,BIT)		REG |= (1<<(BIT))
#define ClrBit(REG,BIT)		REG &= (~(1<<(BIT)))	
#define TogBit(REG,BIT)		REG ^= (1<<(BIT))
#define GetBit(REG,BIT)		(1 & ((REG) >> (BIT))) 


#endif /* BITMATH_H_ */