/*
 * Reg.h
 *
 * Created: 9/30/2022 5:00:58 PM
 *  Author: Aya
  */ 


#ifndef REG_H_
#define REG_H_

#include "StdTypes.h"
/***********************_DIO Registers_***********************/

#define PINA		*((volatile u8*)0x39) 
#define PINB		*((volatile u8*)0x36)
#define PINC		*((volatile u8*)0x33)
#define PIND		*((volatile u8*)0x30)
					 
#define DDRA		*((volatile u8*)0x3A)
#define DDRB		*((volatile u8*)0x37)
#define DDRC		*((volatile u8*)0x34)
#define DDRD		*((volatile u8*)0x31)
					
#define PORTA		*((volatile u8*)0x3B)
#define PORTB		*((volatile u8*)0x38)
#define PORTC		*((volatile u8*)0x35)
#define PORTD		*((volatile u8*)0x32)

/***********************_EXT_TNT_Registers_***********************/
#define MCUCR		*((volatile u8*)0x55)
#define GICR		*((volatile u8*)0x5B)
#define SREG		*((volatile u8*)0x5F)


/***********************_ADC_Registers_***********************/
#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCH		*((volatile u8*)0x25)
#define ADCL		*((volatile u8*)0x24)

/***********************_TIMER0_Registers_***********************/
#define TCCR0		*((volatile u8*)0x53)
#define TIMSK		*((volatile u8*)0x59)
#define TCNT0		*((volatile u8*)0x52)
#define OCR0		*((volatile u8*)0x5C)

/***********************_TIMER2_Registers_***********************/
#define TCCR2		*((volatile u8*)0x45)
#define TCNT2		*((volatile u8*)0x44)
#define OCR2		*((volatile u8*)0x43)

#define FOC2		7
#define WGM20		6
#define COM21		5
#define	COM20		4
#define WGM21		3
#define CS22		2
#define	CS21		1
#define	CS20		0

/***********************_TIMER1_Registers_***********************/
#define TCCR1A		*((volatile u8*)0x4F)
#define TCCR1B		*((volatile u8*)0x4E)
#define TCNT1L		*((volatile u8*)0x4C)
#define TCNT1H		*((volatile u8*)0x4D)
#define OCR1A		*((volatile u16*)0x4A)
#define TIFR		*((volatile u16*)0x58)
#define ICR1		*((volatile u16*)0x46)
/***********************_WDT_Registers_***********************/
#define WDTCR		*((volatile u16*)0x41)
/***********************_UART_Registers_***********************/
#define UCSRA		*((volatile u8*)0x2B)
#define UCSRB		*((volatile u8*)0x2A)
#define UCSRC		*((volatile u8*)0x40)
#define UDR			*((volatile u8*)0x2C)
#define UBRRL		*((volatile u8*)0x29)
#define UBRRH		*((volatile u8*)0x40)
/***********************_UART_Registers_***********************/
#define SPCR		*((volatile u8*)0x2D)
#define SPSR		*((volatile u8*)0x2E)
#define SPDR		*((volatile u8*)0x2F)
/***********************_I2C_REGISTERS_***********************/
#define TWAR 		*((volatile u8*)0x22)
#define TWDR		*((volatile u8*)0x23)
#define TWSR		*((volatile u8*)0x21)
#define TWCR		*((volatile u8*)0x56)
#define TWBR	    *((volatile u8*)0x20)
#endif /* REG_H_ */