/******libraies******/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/*****MCAL**********/
#include"DIO_private.h"
#include"DIO_Interface.h"
#include"DIO_Configue.h"

/******************************/
// for  setting direction  of pins and it's intial values 
void DIO_voidInit(void){
	
	//SET DIRECTION ON DRRX 
   DIO_u8_DDRA_REG=CONC(DIO_u8_PA7_INTIAL_DIRECTION ,
                        DIO_u8_PA6_INTIAL_DIRECTION ,
                        DIO_u8_PA5_INTIAL_DIRECTION ,
                        DIO_u8_PA4_INTIAL_DIRECTION ,
                        DIO_u8_PA3_INTIAL_DIRECTION ,
                        DIO_u8_PA2_INTIAL_DIRECTION ,
                        DIO_u8_PA1_INTIAL_DIRECTION ,
                        DIO_u8_PA0_INTIAL_DIRECTION );
	
	
   DIO_u8_DDRB_REG=CONC(DIO_u8_PB7_INTIAL_DIRECTION ,
                        DIO_u8_PB6_INTIAL_DIRECTION ,
                        DIO_u8_PB5_INTIAL_DIRECTION ,
                        DIO_u8_PB4_INTIAL_DIRECTION ,
                        DIO_u8_PB3_INTIAL_DIRECTION ,
                        DIO_u8_PB2_INTIAL_DIRECTION ,
                        DIO_u8_PB1_INTIAL_DIRECTION ,
                        DIO_u8_PB0_INTIAL_DIRECTION );
						
						
						
   DIO_u8_DDRC_REG=CONC(DIO_u8_PC7_INTIAL_DIRECTION ,
                        DIO_u8_PC6_INTIAL_DIRECTION ,
                        DIO_u8_PC5_INTIAL_DIRECTION ,
                        DIO_u8_PC4_INTIAL_DIRECTION ,
                        DIO_u8_PC3_INTIAL_DIRECTION ,
                        DIO_u8_PC2_INTIAL_DIRECTION ,
                        DIO_u8_PC1_INTIAL_DIRECTION ,
                        DIO_u8_PC0_INTIAL_DIRECTION );	

   DIO_u8_DDRD_REG=CONC(DIO_u8_PD7_INTIAL_DIRECTION ,
                        DIO_u8_PD6_INTIAL_DIRECTION ,
                        DIO_u8_PD5_INTIAL_DIRECTION ,
                        DIO_u8_PD4_INTIAL_DIRECTION ,
                        DIO_u8_PD3_INTIAL_DIRECTION ,
                        DIO_u8_PD2_INTIAL_DIRECTION ,
                        DIO_u8_PD1_INTIAL_DIRECTION ,
                        DIO_u8_PD0_INTIAL_DIRECTION );	





//SET INIAL VALUE ON PORTX 
  DIO_u8_PORTA_REG=CONC(DIO_u8_PA7_INTIAL_VALUE ,
                        DIO_u8_PA6_INTIAL_VALUE ,
                        DIO_u8_PA5_INTIAL_VALUE ,
                        DIO_u8_PA4_INTIAL_VALUE ,
                        DIO_u8_PA3_INTIAL_VALUE ,
                        DIO_u8_PA2_INTIAL_VALUE ,
                        DIO_u8_PA1_INTIAL_VALUE ,
                        DIO_u8_PA0_INTIAL_VALUE );
										 
										 
										  
  DIO_u8_PORTB_REG=CONC(DIO_u8_PB7_INTIAL_VALUE ,
                        DIO_u8_PB6_INTIAL_VALUE ,
                        DIO_u8_PB5_INTIAL_VALUE ,
                        DIO_u8_PB4_INTIAL_VALUE ,
                        DIO_u8_PB3_INTIAL_VALUE ,
                        DIO_u8_PB2_INTIAL_VALUE ,
                        DIO_u8_PB1_INTIAL_VALUE ,
                        DIO_u8_PB0_INTIAL_VALUE );
										 
										
										
  DIO_u8_PORTC_REG=CONC(DIO_u8_PC7_INTIAL_VALUE ,
                        DIO_u8_PC6_INTIAL_VALUE ,
                        DIO_u8_PC5_INTIAL_VALUE ,
                        DIO_u8_PC4_INTIAL_VALUE ,
                        DIO_u8_PC3_INTIAL_VALUE ,
                        DIO_u8_PC2_INTIAL_VALUE ,
                        DIO_u8_PC1_INTIAL_VALUE ,
                        DIO_u8_PC0_INTIAL_VALUE );	
										 
										 
										 
  DIO_u8_PORTD_REG=CONC(DIO_u8_PD7_INTIAL_VALUE ,
                        DIO_u8_PD6_INTIAL_VALUE ,
                        DIO_u8_PD5_INTIAL_VALUE ,
                        DIO_u8_PD4_INTIAL_VALUE ,
                        DIO_u8_PD3_INTIAL_VALUE ,
                        DIO_u8_PD2_INTIAL_VALUE ,
                        DIO_u8_PD1_INTIAL_VALUE ,
                        DIO_u8_PD0_INTIAL_VALUE );					




						
}





u8 DIO_u8SetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDirection){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	
	/***check port and pin within range or not****/
	//because number is unsigned so (Copy_u8PortId>= DIO_u8_PORTA)&&(Copy_u8PinId>=DIO_u8_PIN0) doesnot required
	//check he give me two macros except output or input 
	if((Copy_u8PortId<=DIO_u8_PORTD)&&(Copy_u8PinId<=DIO_u8_PIN7)&&((Copy_u8PinDirection==DIO_u8_OUTPUT)||(Copy_u8PinDirection==DIO_u8_INPUT))){
		
		switch(Copy_u8PortId){
			case DIO_u8_PORTA :
			switch(Copy_u8PinDirection){
			//check direction
			case DIO_u8_OUTPUT:
			 SET_BIT( DIO_u8_DDRA_REG,Copy_u8PinId);
			 break;
			 /*********************/
			 case DIO_u8_INPUT:
			 CLR_BIT( DIO_u8_DDRA_REG,Copy_u8PinId);
			  break;
			}
			break;
			/**************************************/
			case DIO_u8_PORTB :
			switch(Copy_u8PinDirection){
			//check direction
			case DIO_u8_OUTPUT:
			 SET_BIT( DIO_u8_DDRB_REG,Copy_u8PinId);
			 break;
			 /*********************/
			 case DIO_u8_INPUT:
			 CLR_BIT( DIO_u8_DDRB_REG,Copy_u8PinId);
			  break;
			}
			break;
			/***************************************/
			case DIO_u8_PORTC :
			switch(Copy_u8PinDirection){
			//check direction
			case DIO_u8_OUTPUT:
			 SET_BIT( DIO_u8_DDRC_REG,Copy_u8PinId);
			 break;
			 /********************/
			 case DIO_u8_INPUT:
			 CLR_BIT( DIO_u8_DDRC_REG,Copy_u8PinId);
			  break;
			}
			break;
			/****************************************/
			case DIO_u8_PORTD :
			switch(Copy_u8PinDirection){
			//check direction
			case DIO_u8_OUTPUT:
			 SET_BIT( DIO_u8_DDRD_REG,Copy_u8PinId);
			 break;
			 /*********************/
			 case DIO_u8_INPUT:
			 CLR_BIT( DIO_u8_DDRD_REG,Copy_u8PinId);
			  break;
			}
			break;
			
		}
	}
	
	/********************************************/
	else{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}  






/***************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	
	/***check port and pin within range or not****/
	if(Copy_u8PinId<=DIO_u8_PIN7){
		switch(Copy_u8PortId){
			case DIO_u8_PORTA :
			if(Copy_u8PinValue==DIO_u8_HIGH){
				SET_BIT( DIO_u8_PORTA_REG,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_u8_LOW){
				 CLR_BIT( DIO_u8_PORTA_REG,Copy_u8PinId);
			}
			else{
				 Local_u8ErrorState=STD_TYPES_NOK;
			}
			 break;

			/**************************************/
			case DIO_u8_PORTB :
			if(Copy_u8PinValue==DIO_u8_HIGH){
				SET_BIT( DIO_u8_PORTB_REG,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_u8_LOW){
				 CLR_BIT( DIO_u8_PORTB_REG,Copy_u8PinId);
			}
			else{
				 Local_u8ErrorState=STD_TYPES_NOK;
			} 
			 break;


			/***************************************/
			case DIO_u8_PORTC :
			if(Copy_u8PinValue==DIO_u8_HIGH){
				SET_BIT( DIO_u8_PORTC_REG,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_u8_LOW){
				 CLR_BIT( DIO_u8_PORTC_REG,Copy_u8PinId);
			}
			else{
				 Local_u8ErrorState=STD_TYPES_NOK;
			}
			 break;

			/****************************************/
			case DIO_u8_PORTD :
			if(Copy_u8PinValue==DIO_u8_HIGH){
				SET_BIT( DIO_u8_PORTD_REG,Copy_u8PinId);
			}
			else if(Copy_u8PinValue==DIO_u8_LOW){
				 CLR_BIT( DIO_u8_PORTD_REG,Copy_u8PinId);
			}
			else{//for wrong value
				 Local_u8ErrorState=STD_TYPES_NOK;
			}
			 break;
			 /****************************************/
			 default:// for wrrong port
			 Local_u8ErrorState=STD_TYPES_NOK;
			 break;
        	}
	}
             /********************************************/
			 else{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
/*********************************************************************/


u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_pu8ReturnPinValue){
	
		u8 Local_u8ErrorState=STD_TYPES_OK;
		if((Copy_u8PinId<=DIO_u8_PIN7)&&(Copy_pu8ReturnPinValue!=NULL)){//NULL to avoid wild pointer
		switch(Copy_u8PortId){
			case DIO_u8_PORTA :
			*Copy_pu8ReturnPinValue=GET_BIT(DIO_u8_PINA_REG, Copy_u8PinId);
			break;
			case DIO_u8_PORTB :
			*Copy_pu8ReturnPinValue=GET_BIT(DIO_u8_PINB_REG, Copy_u8PinId);
			break;
			case DIO_u8_PORTC :
			*Copy_pu8ReturnPinValue=GET_BIT(DIO_u8_PINC_REG, Copy_u8PinId);
			break;
			case DIO_u8_PORTD :
			*Copy_pu8ReturnPinValue=GET_BIT(DIO_u8_PIND_REG, Copy_u8PinId);
			break;
			default:
			 Local_u8ErrorState=STD_TYPES_NOK;
			 break;
		}}
	
	else{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return  Local_u8ErrorState;
} 


/*************************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId,u8 Copy_u8PortDirection){
		u8 Local_u8ErrorState=STD_TYPES_OK;
		if((Copy_u8PortDirection==DIO_u8_OUTPUT)||(Copy_u8PortDirection==DIO_u8_OUTPUT)){
			switch(Copy_u8PortId){
			case DIO_u8_PORTA :
			switch(Copy_u8PortDirection){
			case DIO_u8_OUTPUT:
			DIO_u8_DDRA_REG=0xff;
			break;
			case DIO_u8_INPUT:
			DIO_u8_DDRA_REG=0x00;
			break;
			}
		break;
		
		
		case DIO_u8_PORTB :
			switch(Copy_u8PortDirection){
			case DIO_u8_OUTPUT:
			DIO_u8_DDRB_REG=0xff;
			break;
			case DIO_u8_INPUT:
			DIO_u8_DDRB_REG=0x00;
			break;
			}
		break;
		
		
		case DIO_u8_PORTC :
			switch(Copy_u8PortDirection){
			case DIO_u8_OUTPUT:
			DIO_u8_DDRC_REG=0xff;
			break;
			case DIO_u8_INPUT:
			DIO_u8_DDRC_REG=0x00;
			break;
			}
		break;
		
		
		case DIO_u8_PORTD :
			switch(Copy_u8PortDirection){
			case DIO_u8_OUTPUT:
			DIO_u8_DDRD_REG=0xff;
			break;
			case DIO_u8_INPUT:
			DIO_u8_DDRD_REG=0x00;
			break;
			}
		break;
		
		default:
		     Local_u8ErrorState=STD_TYPES_NOK;
			 break;

		}
		
		}
	
		
	return  Local_u8ErrorState;
	
}

/************************************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	
	/***check port and pin within range or not****/
	
		switch(Copy_u8PortId){
			case DIO_u8_PORTA :
			 DIO_u8_PORTA_REG=Copy_u8PortValue;
			 break;

			/**************************************/
			case DIO_u8_PORTB :
			 DIO_u8_PORTB_REG=Copy_u8PortValue;
			 break;

			/***************************************/
			case DIO_u8_PORTC :
			 DIO_u8_PORTC_REG=Copy_u8PortValue;
			 break;

			/****************************************/
			case DIO_u8_PORTD :
			 DIO_u8_PORTD_REG=Copy_u8PortValue;
			 break;
			 /****************************************/
			 default:
			 Local_u8ErrorState=STD_TYPES_NOK;
			 break;
		}
             /********************************************/
		

	return Local_u8ErrorState;
} 


u8 DIO_u8GetPortValue(u8 Copy_u8PortId,u8*Copy_pu8ReturnPortValue){
	
	
		u8 Local_u8ErrorState=STD_TYPES_OK;
		
		if(Copy_pu8ReturnPortValue!=NULL){//NULL to avoid wild pointer
		switch(Copy_u8PortId){
			case DIO_u8_PORTA :
			*Copy_pu8ReturnPortValue=DIO_u8_PINA_REG;
			break;
			case DIO_u8_PORTB :
			*Copy_pu8ReturnPortValue=DIO_u8_PINB_REG;
			break;
			case DIO_u8_PORTC :
			*Copy_pu8ReturnPortValue=DIO_u8_PINC_REG;
			break;
			case DIO_u8_PORTD :
			*Copy_pu8ReturnPortValue=DIO_u8_PIND_REG;
			break;
			default:
			 Local_u8ErrorState=STD_TYPES_NOK;
			 break;
		}}
		else{
			 Local_u8ErrorState=STD_TYPES_NOK;
		}
	
	return  Local_u8ErrorState;
	
	
}  
 
