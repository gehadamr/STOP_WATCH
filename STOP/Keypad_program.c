/*
 * Keypad_program.c
 *
 *  Created on: Aug 23, 2024
 *      Author: asus
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#define F_CPU 8000000UL // for  adjust clk freq for using delay to avoid default freq 10000000UL
#include<util/delay.h>
/*****MCAL**********/
#include"DIO_private.h"
#include"DIO_Interface.h"
#include"DIO_Configue.h"

/********HAL********/

#include"Keypad_interface.h"
#include"Keypad_configue.h"
#include"Keypad_Private.h"

 const u8 KEYPAD_Au8Keys[4][4]=KEYPAD_KEYS;
 const u8 KEYPAD_Au8RowsPins[]={KEYPAD_u8_R1_PIN, KEYPAD_u8_R2_PIN, KEYPAD_u8_R3_PIN, KEYPAD_u8_R4_PIN};
 const u8 KEYPAD_Au8ColsPins[]={KEYPAD_u8_C1_PIN, KEYPAD_u8_C2_PIN, KEYPAD_u8_C3_PIN, KEYPAD_u8_C4_PIN};


  u8 KEYPAD_u8GetKeyState(u8*Copy_ReturnedKey){
	u8 Local_u8ReturnedKey;
	u8 Local_u8Flag=0;
	u8 Local_u8ErrorState=STD_TYPES_OK;
	*Copy_ReturnedKey=KEYPAPD_u8_KEY_NOT_Pressed; // i give him intial value to avoid garbge value when the no key is pressed
	/**check wild pointer***/
	if(Copy_ReturnedKey!=NULL){
		for(u8 i=0;i<4;i++){
			DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_Au8RowsPins[i],DIO_u8_LOW);
			for(u8 j=0;j<4;j++){
				//Copy_ReturnedKey  -----> return high or low  but i need to return
			DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_Au8ColsPins[j],&Local_u8ReturnedKey);
			if(Local_u8ReturnedKey==DIO_u8_LOW){			//button pressed
				/*****debouncing****/
				_delay_ms(20);
				DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_Au8ColsPins[j],&Local_u8ReturnedKey);
				 while(Local_u8ReturnedKey==DIO_u8_LOW){
						DIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_Au8ColsPins[j],&Local_u8ReturnedKey);

				 }
				  Local_u8Flag=1;
				*Copy_ReturnedKey=KEYPAD_Au8Keys[i][j];
				break;
			}

			}
			/*deactivate row*/
			DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_Au8RowsPins[i],DIO_u8_HIGH);
			if(Local_u8Flag){
				break;
			}

		}

	}
	else{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return 	Local_u8ErrorState ;
}
