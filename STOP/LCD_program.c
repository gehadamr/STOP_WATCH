/*
 * LCD_program.c
 *
 *  Created on: Aug 22, 2024
 *      Author: asus
 */
/*******lib******/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#define F_CPU 8000000UL // for  adjust clk freq for using delay to avoid default freq 10000000UL
#include<util/delay.h>
/******MCAL*****/
#include"DIO_Interface.h"
/*****HAL****/
#include"LCD_Interface.h"
#include "LCD_Private.h"
#include"LCD_Config.h"

void LCD_voidIntit(){
//delay >30ms  say  35ms
/*send functionset command 0b00001 DL N F - -  |0b00111000
DL control if i send data on 4 bit(DL=0) or 8 bit (DL=1)
N num of Lines 	one line--->0   |two Lines ----->1
F  set character font 0--->5x7   |  1---->5x10   */
//_delay_us(40)
/*send Display on/off cmd  0b00001 D C B  | 0b00001111
D: displayon 1 |displayoff 0
C: cursor dispaly-->1  |hidden cursor--->0   only for 5x7font
B: blinking--->1 Static --->0
*/
//_delay_us(40)
/*	send DisplayClear 0b00000001*/
//_delay_ms(2)
//send Entry Mode SET cmd 0b000001 I/D SH
//I/D: increase ->>right(default=1) | decrease--<<left 0
// SH: shifting right (SH=1&&I/D=0 )  |shifting left (SH=1&&I/D=1 ) | no shifting =0
#if LCD_u8_MODE==LCD_u8_MODE_8_BIT
	_delay_ms(35);
	LCD_SendCommand(MODE_8_FUNCTIONSET);
	_delay_us(40);
	LCD_SendCommand(MODE_8_DISPLAY_ON_OFF);
	_delay_us(40);
	LCD_SendCommand(MODE_8_CLEAR);
	_delay_ms(2);
	LCD_SendCommand( MODE_8_ENTRYMODESET);

#elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	_delay_ms(35);
	 LCD_SendCommand(MODE_4_FUNCTIONSET_P1);
	 LCD_SendCommand(MODE_4_FUNCTIONSET_P1);
	 LCD_SendCommand(MODE_4_FUNCTIONSET_P2);
	 _delay_us(40);
	 LCD_SendCommand(MODE_4_DISPLAY_ON_OFF_P1);
	 LCD_SendCommand(MODE_4_DISPLAY_ON_OFF_P2);
	 _delay_us(40);
	 LCD_SendCommand(MODE_4_CLEAR_P1);
	 LCD_SendCommand(MODE_4_CLEAR_P2);
	 _delay_ms(2);
	 LCD_SendCommand(MODE_4_ENTRYMODESET_P1);
	 LCD_SendCommand(MODE_4_ENTRYMODESET_P2);

#endif


}
void LCD_SendCommand(u8 Copy_u8Command){
// rs  0 cmd
//rw   0 write
//write command
//enable 1
//enable 0 to make pulse

#if LCD_u8_MODE==LCD_u8_MODE_8_BIT
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Command);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
    _delay_us(1);
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);


#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
    // Set RS and RW to 0 for command mode
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, DIO_u8_LOW);
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, DIO_u8_LOW);

    // Send the higher nibble (D7-D4)
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN4, GET_BIT(Copy_u8Command, 4));
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN5, GET_BIT(Copy_u8Command, 5));
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN6, GET_BIT(Copy_u8Command, 6));
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN7, GET_BIT(Copy_u8Command, 7));

    // Generate Enable pulse
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);
    _delay_us(1);  // Wait for at least 1us
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

    // Send the lower nibble (D3-D0)
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN4, GET_BIT(Copy_u8Command, 0));
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN5, GET_BIT(Copy_u8Command, 1));
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN6, GET_BIT(Copy_u8Command, 2));
    DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN7, GET_BIT(Copy_u8Command, 3));

    // Generate Enable pulse again
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);
    _delay_us(1);  // Wait for at least 1us
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);
    _delay_us(40);

#endif
}


void LCD_SendChar(u8 Copy_u8Char){
	// rs  1  data
	//rw   0 write
	//write command
	//enable 1
	//enable 0 to make pulse
#if LCD_u8_MODE==LCD_u8_MODE_8_BIT
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
		DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
		DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_HIGH);
	    _delay_us(1);
	    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_EN_PIN,DIO_u8_LOW);


#elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN4, GET_BIT( Copy_u8Char, 4));
	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN5, GET_BIT( Copy_u8Char, 5));
	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN6, GET_BIT( Copy_u8Char, 6));
	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN7, GET_BIT( Copy_u8Char, 7));

	       // Generate Enable pulse
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);
	       _delay_us(2);
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);


	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN4, GET_BIT( Copy_u8Char, 0));
	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN5, GET_BIT( Copy_u8Char, 1));
	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN6, GET_BIT( Copy_u8Char, 2));
	       DIO_u8SetPinValue(LCD_u8_DATA_PORT, DIO_u8_PIN7, GET_BIT( Copy_u8Char, 3));

	       // Generate Enable pulse
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_HIGH);
	       _delay_us(2);
	       DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN, DIO_u8_LOW);

#endif
}


void LCD_SendString ( const u8 *Copy_pu8arr){
	if(Copy_pu8arr!=NULL){
	u8 i=0;
		while(Copy_pu8arr[i]!='\0'){
			LCD_SendChar(Copy_pu8arr[i]);
			i++;
		}
	}
}


void LCD_SendNumber(s32 Copy_u8Number) {
    u8 arr[12];
    u8 i = 0;


    if (Copy_u8Number == 0) {
        LCD_SendChar('0');
        return;
    }

    if (Copy_u8Number < 0) {
        LCD_SendChar('-');
        Copy_u8Number = -1*Copy_u8Number;
    }


    while (Copy_u8Number != 0) {
        u8 LastDigit = Copy_u8Number % 10;
        arr[i] = (LastDigit + '0');
        Copy_u8Number /= 10;
        i++;
    }

    for (u8 j = 0; j < i; j++) {
        LCD_SendChar(arr[i - j - 1]);
    }
}



u8 LCD_u8GOTOXY(u8 Copy_u8LineNum,u8 Copy_u8Location){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_u8Location<=39){//40location in each line
		switch(Copy_u8LineNum){
		case LCD_u8_LINE1:
			LCD_SendCommand(0x80+Copy_u8Location);
			break;

		case LCD_u8_LINE2:
			LCD_SendCommand(0xC0+Copy_u8Location);
			break;

		default:
			Local_u8ErrorState=STD_TYPES_NOK;
		}

	}
	else{

		Local_u8ErrorState=STD_TYPES_NOK;
	}
return Local_u8ErrorState;
}
void LCD_displaySpecialChar(u8 CharNum, u8* ptr, u8 row, u8 col) {
    if (CharNum > 7) {
        return;
    }

    // Set CGRAM address cmd
    LCD_SendCommand(0b01000000 | (CharNum << 3));
/*CGRAM 0b01 (p5---p0) location
 * say charnum 2
 * 0b00000010>>3
 *  after shifting :0b00010000
 *  0b01000000|0b00010000 =0b01010000
 */
 //store pattern in the CGRAM
    for (u8 i = 0; i < 8; i++) {
        LCD_SendChar(ptr[i]);
    }

    // Set  CA TO DDRAM address
    LCD_u8GOTOXY(row, col);

    // Display  character on DDRAM
    LCD_SendChar(CharNum);
}


void LCD_voidClear(){
	LCD_SendCommand(lcd_Clear);
	_delay_ms(2);
}
