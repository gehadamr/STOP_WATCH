/*
 * TIMER0_Private.h
 *
 *  Created on: Aug 30, 2024
 *      Author: asus
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
//timer reg
#define TIMER0_TIMSK *((volatile u8*)0x59)//PIE
#define TIMER0_TIFR  *((volatile u8*)0x58)//PIF
#define TIMER0_TCCR0 *((volatile u8*)0x53)//intialization
#define TIMER0_TCNT0 *((volatile u8*)0x52)//normal mode
#define TIMER0_OCR0  *((volatile u8*)0x5C)//ctc mode

//timer1 reg
#define TIMER1_TCCR1A  *((volatile u8*)0x4F)
#define TIMER1_TCCR1B  *((volatile u8*)0x4E)
#define TIMER1_TCNT1   *((volatile u16*)0x4C)
#define TIMER1_OCR1A   *((volatile u16*)0x4A)
#define TIMER1_ICR     *((volatile u16*)0x46)
#define TIMER1_OCR1B   *((volatile u16*)0x48)

#endif /* TIMER0_PRIVATE_H_ */
