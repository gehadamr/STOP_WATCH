#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>
#include "DIO_Interface.h"
#include "GIE_interface.h"
#include "TIMER0_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_interface.h"

void STOP_WATCH();
void SetInitialTime();

static u8 sec = 0;
static u8 min = 0;
static u8 hr = 0;

int main() {
    u8 keyPressed = KEYPAPD_u8_KEY_NOT_Pressed;

    // Initialize DIO
    DIO_voidInit();

    // Initialize LCD
    LCD_voidIntit();
  // Enable Global Interrupt
    GIE_Enable();

    // Set initial time using the keypad
    SetInitialTime();

    KEYPAD_u8GetKeyState(&keyPressed);
    // Wait for the start button 'S'
    while (keyPressed != 'S') {
        KEYPAD_u8GetKeyState(&keyPressed);
    }


    // Initialize Timer0
    TIMER0_void_Inti();
    TIMER0_u8_TIMER0SETCALLBACK_ovf(&STOP_WATCH);


    while (1) {

    }
}

void STOP_WATCH() {
    if (sec > 0) {
        sec--;
    } else {
        sec = 59;
        if (min > 0) {
            min--;
        } else {
            min = 59;
            if (hr > 0) {
                hr--;
            } else {
                hr = 0;
            }
        }
    }

    LCD_voidClear();
    LCD_SendNumber(hr);
    LCD_SendChar(':');
    LCD_SendNumber(min);
    LCD_SendChar(':');
    LCD_SendNumber(sec);
}

void SetInitialTime() {
    u8 cursorPosition = 0;
    u8 Hr = 0, Min = 0, Sec = 0;
    u8 value = KEYPAPD_u8_KEY_NOT_Pressed;

    LCD_voidClear();
    LCD_u8GOTOXY(LCD_u8_LINE1, 0);
    LCD_SendNumber(Hr);
    LCD_u8GOTOXY(LCD_u8_LINE1,2);
    LCD_SendChar(':');
    LCD_SendNumber(Min);
    LCD_u8GOTOXY(LCD_u8_LINE1,5);
    LCD_SendChar(':');
    LCD_SendNumber(Sec);

    while (1) {
        KEYPAD_u8GetKeyState(&value);
        if (value != KEYPAPD_u8_KEY_NOT_Pressed) {
            if (value >= 0 && value <= 9) {
                if (cursorPosition == 0) {//
                    Hr = Hr * 10 + (value );
                    LCD_u8GOTOXY(LCD_u8_LINE1, 0);
                    LCD_SendNumber(Hr);
                } else if (cursorPosition == 1) {//min
                    Min = Min * 10 + (value);
                    LCD_u8GOTOXY(LCD_u8_LINE1, 3);
                    LCD_SendNumber(Min);
                } else if (cursorPosition == 2) {//sec
                    Sec = Sec * 10 + (value);
                    LCD_u8GOTOXY(LCD_u8_LINE1, 6);
                    LCD_SendNumber(Sec);
                }

            }

            if (value == 'R') {
                cursorPosition = (cursorPosition + 1) % 3;
            } else if (value == 'L') {
                cursorPosition = (cursorPosition - 1 + 3) % 3;
            } else if (value == 'E') {
                hr = Hr;
                min = Min;
                sec = Sec;
                break;
            }
        }
    }
}

/***************************************************
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>
#include "DIO_Interface.h"
#include "GIE_interface.h"
#include "TIMER0_Interface.h"
#include "LCD_Interface.h"
void STOP_WATCH();

static u8 sec=0;
static u8 min=0;
static u8 hr=0;
int main() {
    // Initialize DIO
    DIO_voidInit();
    // Initialize LCD
    LCD_voidIntit();
    // Enable Global Interrupt
    GIE_Enable();
    // Initialize Timer0
    TIMER0_void_Inti();
    TIMER0_u8_TIMER0SETCALLBACK_ovf(&STOP_WATCH);

    while (1) {

   }
}

void STOP_WATCH(){
	sec++;
	if(sec==60){
		sec=0;
		min++;}
		if(min==60){
			min=0;
			hr++;}
			if(hr==60){
				hr=0;}
            LCD_voidClear();
			LCD_SendNumber(hr);
			LCD_SendChar(':');
			LCD_SendNumber(min);
			LCD_SendChar(':');
			LCD_SendNumber(sec);
}*/
