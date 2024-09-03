/*
 * LCD_Config.h
 *
 *  Created on: Aug 22, 2024
 *      Author: asus
 */
/**preprocessor file**/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*
 DIO_u8_PORTA
 DIO_u8_PORTB
 DIO_u8_PORTC
 DIO_u8_PORTD */

#define LCD_u8_CONTROL_PORT   DIO_u8_PORTC

/*
DIO_u8_PIN0
DIO_u8_PIN1
DIO_u8_PIN2
DIO_u8_PIN3
DIO_u8_PIN5
DIO_u8_PIN5
DIO_u8_PIN6
DIO_u8_PIN7 */

#define LCD_u8_RS_PIN   DIO_u8_PIN0
#define LCD_u8_RW_PIN   DIO_u8_PIN1
#define LCD_u8_EN_PIN   DIO_u8_PIN2

#define LCD_u8_DATA_PORT   DIO_u8_PORTA
#endif
