/*
 * TIMER0_Interface.h
 *
 *  Created on: Aug 30, 2024
 *      Author: asus
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


/*timer0pins*/
//TCCR0 reg pins
#define TIMER0_FOC0_PIN  7
#define TIMER0_WGM00_PIN 6
#define TIMER0_COM01_PIN 5
#define TIMER0_COM00_PIN 4
#define TIMER0_WGM01_PIN 3
#define TIMER0_CS02_PIN  2
#define TIMER0_CS01_PIN  1
#define TIMER0_CS00_PIN  0

// TCNT_reg pins
#define TIMER0_TCNT0_PIN 0
#define TIMER0_TCNT1_PIN 1
#define TIMER0_TCNT2_PIN 2
#define TIMER0_TCNT3_PIN 3
#define TIMER0_TCNT4_PIN 4
#define TIMER0_TCNT5_PIN 5
#define TIMER0_TCNT6_PIN 6
#define TIMER0_TCNT7_PIN 7
 //TIMSK_reg pins
#define TIMER0_TOIE0_PIN 0
#define TIMER0_OCIE0_PIN 1
//TIFR REG pins
#define TIMER0_TOV0_PIN 0
#define TIMER0_OCF0_PIN 0
//timer modes
#define CTC          0
#define Normal       1
#define FASTPWM      2
#define PhaseCorrect 6

//clk mode
#define prescaler 0
#define ExternalCLkFallingedge  1
#define ExternalCLkRisingedge  2

//timer1 pins
#define TIMER1_COM1A1_PIN 7
#define TIMER1_COM1A0_PIN 6
#define TIMER1_WGM11_PIN 1
#define TIMER1_WGM10_PIN 0
#define TIMER1_WGM13_PIN 4
#define TIMER1_WGM12_PIN 3
#define TIMER1_CS12_PIN 2
#define TIMER1_CS11_PIN 1
#define TIMER1_CS10_PIN 0

void TIMER0_void_Inti(void);
u8 TIMER0_u8_TIMER0SETCALLBACK_ovf(void (*pf)(void));
u8 TIMER0_u8_TIMER0SETCALLBACK_CTC(void (*pf)(void));
void TIMER0_voidTIMER0SetCompareMatch(u8 Copy_u8OCRValue);
void TIMER1_void_Inti(void);
void TIMER1_ICRSetRegValue(u16 Copy_u8TopValue);
void TIMER0_void_ResetCounter();  // Reset Timer0 counter
void TIMER0_void_STOPCounter(void);

#endif /* TIMER0_INTERFACE_H_ */
