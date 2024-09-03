/*
 * LCD_Interface.h
 *
 *  Created on: Aug 22, 2024
 *      Author: asus
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#define LCD_u8_LINE1   1
#define LCD_u8_LINE2   2


//8 bit mode cmd
#define MODE_8_FUNCTIONSET  0b00111000
#define MODE_8_DISPLAY_ON_OFF  0b00001110
#define MODE_8_CLEAR  0b00000001
#define MODE_8_ENTRYMODESET  0b00000110

//used in intialization lcd 4_bit mode taken from data sheet
#define MODE_4_FUNCTIONSET_P1 0b00100000
#define MODE_4_FUNCTIONSET_P2  0b1000000
#define MODE_4_DISPLAY_ON_OFF_P1  0b00000000
#define MODE_4_DISPLAY_ON_OFF_P2  0b11110000
#define MODE_4_CLEAR_P1 0b00000000
#define MODE_4_CLEAR_P2 0b00010000
#define MODE_4_ENTRYMODESET_P1  0b00000000
#define MODE_4_ENTRYMODESET_P2  0b01100000






//comands
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define lcd_shiftCursorLeft   0b00010000
#define lcd_shiftCursorRight  0b00010100
#define lcd_shiftDisplayLeft  0b00011000
#define lcd_shiftDisplayRight 0b00011100
#define Set_CGRAM_address  0b01000000    // Set CGRAM address

void LCD_voidIntit();
void LCD_SendCommand(u8 Copy_u8Command);
void LCD_SendChar(u8 Copy_u8Char);
void LCD_SendString ( const u8 *Copy_pu8arr);
void LCD_SendNumber(s32 Copy_u8Number);
void LCD_SendNumber(s32 Copy_u8Number);
u8 LCD_u8GOTOXY(u8 Copy_u8LineNum,u8 Copy_u8Location);
void LCD_displaySpecialChar(u8 CharNum, u8* ptr, u8 row, u8 col);
void LCD_voidClear();
#endif /* LCD_INTERFACE_H_ */
