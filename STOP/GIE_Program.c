/*
 * GIE_Program.c
 *
 *  Created on: Aug 25, 2024
 *      Author: asus
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "GIE_Private.h"
#include "GIE_interface.h"
void GIE_Enable(void)
{
	/*enable GLOBAL Enable  EXTI0Enable-->GIE*/
		SET_BIT(GIE_u8_SREG,SREGI_BIT);
}
void GIE_disable(void)
{
CLR_BIT(GIE_u8_SREG,SREGI_BIT);
}


