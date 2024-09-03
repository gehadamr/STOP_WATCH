/*

 * Keypad_configue.h
 *
 *  Created on: Aug 23, 2024
 *      Author: asus
 */

#ifndef KEYPAD_CONFIGUE_H_
#define KEYPAD_CONFIGUE_H_
/*
DIO_u8_PORTA 0
DIO_u8_PORTB 1
DIO_u8_PORTC 2
DIO_u8_PORTD 3
*/
/*
 DIO_u8_PIN0 0
 DIO_u8_PIN1 1
 DIO_u8_PIN2 2
 DIO_u8_PIN3 3
 DIO_u8_PIN4 4
 DIO_u8_PIN5 5
 DIO_u8_PIN6 6
 DIO_u8_PIN7 7
*/


#define KEYPAD_PORT  DIO_u8_PORTD

#define KEYPAD_u8_R1_PIN   DIO_u8_PIN0
#define KEYPAD_u8_R2_PIN   DIO_u8_PIN1
#define KEYPAD_u8_R3_PIN   DIO_u8_PIN2
#define KEYPAD_u8_R4_PIN   DIO_u8_PIN3

#define KEYPAD_u8_C1_PIN   DIO_u8_PIN4
#define KEYPAD_u8_C2_PIN   DIO_u8_PIN5
#define KEYPAD_u8_C3_PIN   DIO_u8_PIN6
#define KEYPAD_u8_C4_PIN   DIO_u8_PIN7

/*multi line macros*/
/* to make keypad config easy to handle*/
#define KEYPAD_KEYS            {{1,2,3,'+'},\
		                       {4,5,6,'-'},\
		                       {7,8,9,'E'},\
		                       {'L','R','/','S'}}




#endif /* KEYPAD_CONFIGUE_H_ */
