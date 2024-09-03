/*
 * TIMER0_Program.c
 *
 *  Created on: Aug 30, 2024
 *      Author: asus
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Config.h"
#include "TIMER0_Private.h"

static void (*Global_TIMER0_PF)(void) = NULL;
static void (*Global_TIMER0_PCTC)(void) = NULL;
/***********************timer0******************/
void TIMER0_void_Inti(void) {
    /* Mode selection */
#if(MODE== Normal)
    /* 1- select mode  -->> NORMAL MODE */
    CLR_BIT(TIMER0_TCCR0, TIMER0_WGM00_PIN);
    CLR_BIT(TIMER0_TCCR0, TIMER0_WGM01_PIN);

    /* 2-enable overflow interrupt to be ready for uploading flag after timer complete counting */
    // SET_BIT(TIMER0_TIMSK, TIMER0_TOIE0_PIN);
    /* 3- set preload value */
    TIMER0_TCNT0 = 192;

#elif (MODE == CTC)
    /* 1- select mode  -->> CTC MODE */
    CLR_BIT(TIMER0_TCCR0, TIMER0_WGM00_PIN);
    SET_BIT(TIMER0_TCCR0, TIMER0_WGM01_PIN);

    /* 2-enable CTC interrupt to be ready for uploading flag after timer complete counting */
    // SET_BIT(TIMER0_TIMSK, TIMER0_OCIE0_PIN);
    /* 3-set OCR0 register */
    TIMER0_OCR0 = 99;

#elif (MODE == FASTPWM)
    /* 1- select mode  -->> FAST PWM MODE */
    SET_BIT(TIMER0_TCCR0, TIMER0_WGM00_PIN);
    SET_BIT(TIMER0_TCCR0, TIMER0_WGM01_PIN);

    /* 2- select non-inverting mode */
    SET_BIT(TIMER0_TCCR0, TIMER0_COM01_PIN);
    CLR_BIT(TIMER0_TCCR0, TIMER0_COM00_PIN);

#elif (MODE == PhaseCorrect)
    /* 1- select mode  -->> PHASE CORRECT MODE */
    SET_BIT(TIMER0_TCCR0, TIMER0_WGM00_PIN);
    CLR_BIT(TIMER0_TCCR0, TIMER0_WGM01_PIN);

    /* 2- select Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. */
    SET_BIT(TIMER0_TCCR0, TIMER0_COM01_PIN);
    CLR_BIT(TIMER0_TCCR0, TIMER0_COM00_PIN);

#endif

/* Set prescaler */
#if (CLK_MODE == prescaler)
    CLR_BIT(TIMER0_TCCR0, TIMER0_CS02_PIN);
    SET_BIT(TIMER0_TCCR0, TIMER0_CS01_PIN);
    CLR_BIT(TIMER0_TCCR0, TIMER0_CS00_PIN);

#elif (CLK_MODE == ExternalCLkFallingedge)
    SET_BIT(TIMER0_TCCR0, TIMER0_CS02_PIN);
    SET_BIT(TIMER0_TCCR0, TIMER0_CS01_PIN);
    CLR_BIT(TIMER0_TCCR0, TIMER0_CS00_PIN);
    TIMER0_TCNT0 = 0;

#elif (CLK_MODE == ExternalCLkRisingedge)
    SET_BIT(TIMER0_TCCR0, TIMER0_CS02_PIN);
    SET_BIT(TIMER0_TCCR0, TIMER0_CS01_PIN);
    SET_BIT(TIMER0_TCCR0, TIMER0_CS00_PIN);
    TIMER0_TCNT0 = 0;

#endif
}
void TIMER0_START(void){

}


/* ISR for Timer0 Overflow */
void __vector_11(void)  __attribute__((signal));
void __vector_11(void) {

    static u16 Local_counter = 0;

    Local_counter++;
    if (Local_counter == 3907) {
        /* 1-update preload */
        TIMER0_TCNT0 = 192;
        /* 2-reset counter to 0 */
        Local_counter = 0;
        /* 3-toggle led; function taken from main */
        if (Global_TIMER0_PF != NULL) {
            Global_TIMER0_PF();
        }
    }
}

/* Callback function for Timer0 Overflow */
u8 TIMER0_u8_TIMER0SETCALLBACK_ovf(void (*pf)(void)) {
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if (pf != NULL) {
        Global_TIMER0_PF = pf;
    } else {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    SET_BIT(TIMER0_TIMSK, TIMER0_TOIE0_PIN);
    return Local_u8ErrorState;
}

/* ISR for Timer0 CTC */
void __vector_10(void)  __attribute__((signal));
void __vector_10(void) {

    static u16 Local_counter = 0;
    Local_counter++;
    if (Local_counter == 10000) {
        /* 2-reset counter to 0 */
        Local_counter = 0;
        /* 3-toggle led; function taken from main */
        if (Global_TIMER0_PCTC != NULL) {
            Global_TIMER0_PCTC();
        }
    }
    SET_BIT(TIMER0_TIMSK, TIMER0_OCIE0_PIN);

}

/* Callback function for Timer0 CTC */
u8 TIMER0_u8_TIMER0SETCALLBACK_CTC(void (*pf)(void)) {
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if (pf != NULL) {
        Global_TIMER0_PCTC = pf;
    } else {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}

/* Update OCR value in Fast PWM mode */
void TIMER0_voidTIMER0SetCompareMatch(u8 Copy_u8OCRValue) {
    TIMER0_OCR0 = Copy_u8OCRValue;
}



/**************************timer1***********************/
void TIMER1_void_Inti(void){
	//select mode fast pwm mode
	SET_BIT(TIMER1_TCCR1B,TIMER1_WGM13_PIN);
	SET_BIT(TIMER1_TCCR1B,TIMER1_WGM12_PIN);
	SET_BIT(TIMER1_TCCR1A,TIMER1_WGM11_PIN);
	CLR_BIT(TIMER1_TCCR1A,TIMER1_WGM10_PIN);
     //select  HW action on OC1A pin --->>non inverting
	  SET_BIT(TIMER1_TCCR1A, TIMER1_COM1A1_PIN);
	  CLR_BIT(TIMER1_TCCR1A, TIMER1_COM1A0_PIN);
	  //set ovf value in the ICR1 reg
	  TIMER1_ICR=19999;
	  /*set angle for servo motor*/
	  //say i set it to angle 0
	  TIMER1_OCR1A=999;
	  //set servo to 180

#if (CLK_MODE == prescaler)
    CLR_BIT(TIMER1_TCCR1B, TIMER1_CS12_PIN);
    SET_BIT(TIMER1_TCCR1B, TIMER1_CS11_PIN);
    CLR_BIT(TIMER1_TCCR1B, TIMER1_CS10_PIN);

#elif (CLK_MODE == ExternalCLkFallingedge)
    SET_BIT(TIMER1_TCCR1B, TIMER1_CS12_PIN);
    SET_BIT(TIMER1_TCCR1B, TIMER1_CS11_PIN);
    CLR_BIT(TIMER1_TCCR1B, TIMER1_CS10_PIN);

#elif (CLK_MODE == ExternalCLkRisingedge)
    SET_BIT(TIMER1_TCCR1B, TIMER1_CS12_PIN);
    SET_BIT(TIMER1_TCCR1B, TIMER1_CS11_PIN);
    SET_BIT(TIMER1_TCCR1B, TIMER1_CS10_PIN);

#endif

}


void TIMER1_ICRSetRegValue(u16 Copy_u8TopValue){
	TIMER1_ICR=Copy_u8TopValue;
}

void TIMER0_void_STOPCounter(void){
	TIMER1_TCCR1B&=0b11111000;

}
void TIMER0_void_ResetCounter(){

	TIMER0_TCNT0=0;

	// Reset Timer0 counter
}
u8 TIMER0_Return_TCNT0_Reg(){
	return TIMER0_TCNT0;
}
