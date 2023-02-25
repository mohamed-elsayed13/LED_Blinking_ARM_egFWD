/*****************************************************************************
*
* INCLUDES
*
*****************************************************************************/

#include "SYSTICK_Interface.h"
/*****************************************************************************
*
* DRIVER IMPLEMENTATIONS
*
*****************************************************************************/

/************************************************************************************
* Function Name: SYSTICK_Init
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): TimerConfig - Timer Configurations
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize SysTick with given prescaler and preload values
************************************************************************************/
void SysTick_Init(uint32_t LoadValue)
{
		SYSTICK_CTRL_REG    = 0;              /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = LoadValue;       /* Set the Reload value with 15999999 to count 1 Second */
    SYSTICK_CURRENT_REG = 0;              /* Clear the Current Register value */
    
    /*SYSTICK_CTRL_REG   |= 0x07;*/
		
}

void SysTick_Enable(void)
{
	/* Configure the SysTick Control Register 
     * Enable the SysTick Timer (ENABLE = 1)
     * Enable SysTick Interrupt (INTEN = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
	SYSTICK_CTRL_REG|=(uint32_t)7;
}

void SysTick_Disable(void)
{
	SYSTICK_CTRL_REG|=(uint32_t)6;
}
	
void SysTick_Callback(void (*ptrF) (void))
{
	ptrFCallback = ptrF;
}

void SysTick_Handler(void)
{
	if (ptrFCallback != NULL)
	{
		ptrFCallback();
	}
}
