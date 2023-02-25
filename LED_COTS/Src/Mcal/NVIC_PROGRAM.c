/*****************************************************************************
*
* INCLUDES
*
*****************************************************************************/

#include "NVIC_Interface.h"


void NVIC_EnableINT(NVIC_InterruptType  INT_Number)
{
	switch(INT_Number){
		case NVIC_SYSTICK:
		/* Assign priority level 3 to the SysTick Interrupt */
    NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
		break;
		case NVIC_GPIOF:
		/* Set GPIO PORTF priotiy as 2 by set Bit number 21, 22 and 23 with value 2 */
    NVIC_PRI7_REG = (NVIC_PRI7_REG & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_REG         |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
		break;
		default:
		break;		
	}
}
