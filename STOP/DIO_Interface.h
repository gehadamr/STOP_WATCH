/*************************************/
/***********Name : Jehad Amr**********/
/***********Date : 8/21/2024**********/
/***********swc :DIO******************/
/***********version : 1.0*****************/

/***header guard****/  
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
/*********port macros***********/
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/*********pin macros***********/
#define DIO_u8_PIN0 0 
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2 
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5 
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7 
/****Pin Direction****/
#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT  0 

/*****value Macros*****/
#define DIO_u8_HIGH 1
#define DIO_u8_LOW  0 


//make any function return error variable to indicate that i give the function the required argument or not
void DIO_voidInit(void);
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDirection);  
u8 DIO_u8SetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue);  
u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_pu8ReturnPinValue);  
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection);  
u8 DIO_u8SetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue);  
u8 DIO_u8GetPortValue(u8 Copy_u8PortId,u8 *Copy_pu8ReturnPortValue);   

#endif    
