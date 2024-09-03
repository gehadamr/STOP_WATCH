/*
 *file: DIO_prv.h
 * Name:jehad Amr 
 * Created on: Aug 8, 2024
 * swc: DIO
 * version :1.0
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
/**********************direction of pin in DIO***********/
#define DIO_u8_DDRA_REG *((volatile u8*)(0x3A))// no memory consumption instead using u8*ptr=((u8*)(0x3B));// *ptr= 0b11111111;
#define DIO_u8_DDRB_REG *((volatile u8*)(0x37))
#define DIO_u8_DDRC_REG *((volatile u8*)(0x34))
#define DIO_u8_DDRD_REG *((volatile u8*)(0x31))
/********************PORT VALUE in DIO******************/
#define DIO_u8_PORTA_REG *((volatile u8*)(0x3B))
#define DIO_u8_PORTB_REG *((volatile u8*)(0x38))
#define DIO_u8_PORTC_REG *((volatile u8*)(0x35))
#define DIO_u8_PORTD_REG *((volatile u8*)(0x32))

/*******************READ VALUE in DIO******************/
#define DIO_u8_PINA_REG *((volatile u8*)(0x39))
#define DIO_u8_PINB_REG *((volatile u8*)(0x36))
#define DIO_u8_PINC_REG *((volatile u8*)(0x33))
#define DIO_u8_PIND_REG *((volatile u8*)(0x30))

/***************MACROS FOR PIN DIRECTION************/
 #define DIO_u8_INTIAL_INPUT  0
 #define DIO_u8_INTIAL_OUTPUT 1
 /*************MACROS FOR PIN VALUES ***************/
#define DIO_u8_OUTPUT_HIGH       1
#define DIO_u8_OUTPUT_LOW        0
#define DIO_u8_INPUT_PULLUP      1
#define DIO_u8_INPUT_FLOATING    0
/************conc function like macros**************/
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)          CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* DIO_PRV_H_ */
