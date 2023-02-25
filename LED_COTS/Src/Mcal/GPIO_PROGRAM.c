/*****************************************************************************
*
* INCLUDES
*
*****************************************************************************/

#include "GPIO_Interface.h"

/*****************************************************************************
* Function Name: DIO_init
* Purpose      : Initialize PIN Direction (IN/OUT)
* Parameters   : uint8_t portnumber,uint8_t pinnumber,uint8_t direction
* Return value : void
*****************************************************************************/
void GPIO_init(uint8_t portnumber,uint8_t pinnumber,uint8_t direction){
	switch(portnumber){
		case PORT_F:
		if(direction==OUT){
			/* Enable clock for PORTF and allow time for clock to start */
			volatile unsigned long delay = 0;
			SYSCTL_RCGCGPIO_REG  |= 0x00000020;
			delay = SYSCTL_REGCGC2_REG;
			/* Disable Analog  */
			GPIO_PORTF_AMSEL_REG &= ~(1<<pinnumber);
			/* Clear PMCx bits to use it as GPIO pin */
			GPIO_PORTF_PCTL_REG  &= ~(0x0000000F<<(4*pinnumber));
			/* Disable alternative function  */
			GPIO_PORTF_AFSEL_REG &= ~(1<<pinnumber);
			/* Enable Digital I/O */
			GPIO_PORTF_DEN_REG   |=(1<<pinnumber);
			/* Configure PIN as output pin */
			GPIO_PORTF_DIR_REG |=(1<<pinnumber);
			
		}
		else if (direction==IN){
			/* Enable clock for PORTF and allow time for clock to start */
			volatile unsigned long delay = 0;
			SYSCTL_RCGCGPIO_REG  |= 0x00000020;
			delay = SYSCTL_REGCGC2_REG;
			if(pinnumber==0){
			/* Unlock the GPIO_PORTF_CR_REG */	
			GPIO_PORTF_LOCK_REG   = 0x4C4F434B;
			/* Enable changes on PF0 */	
			GPIO_PORTF_CR_REG    |= (1<<pinnumber);       
			}
			/* Disable Analog  */
			GPIO_PORTF_AMSEL_REG &= ~(1<<pinnumber);
			/* Clear PMCx bits to use it as GPIO pin */
			GPIO_PORTF_PCTL_REG  &= ~(0x0000000F<<(4*pinnumber));
			/* Disable alternative function  */
			GPIO_PORTF_AFSEL_REG &= ~(1<<pinnumber);
			/* Enable pull-up */
			GPIO_PORTF_PUR_REG   |=(1<<pinnumber); 
			/* Enable Digital I/O */
			GPIO_PORTF_DEN_REG   |=(1<<pinnumber);
			/* Configure PIN as output pin */
			GPIO_PORTF_DIR_REG 	 &=~(1<<pinnumber);
			/* Pin detect edges */
			GPIO_PORTF_IS_REG    &= ~(1<<pinnumber);      
			/* Pin will detect a certain edge */
			GPIO_PORTF_IBE_REG   &= ~(1<<pinnumber); 
			/* Pin will detect a falling edge */			
			GPIO_PORTF_IEV_REG   &= ~(1<<pinnumber);      
			/* Clear Trigger flag (Interupt Flag) */
			GPIO_PORTF_ICR_REG   |= (1<<pinnumber);       
			/* Enable Interrupt  */
			GPIO_PORTF_IM_REG    |= (1<<pinnumber);       
		}
		else{
			/*error*/
		}
		break;
		default:
		break;
	}
}
/*****************************************************************************
* Function Name: GPIO_write
* Purpose      : Write (High/LOW) for specific PIN 
* Parameters   : uint8_t portnumber,uint8_t pinnumber,uint8_t value
* Return value : void
*****************************************************************************/
void GPIO_write(uint8_t portnumber,uint8_t pinnumber,uint8_t value){
	switch(portnumber){
		case PORT_F:
		if(value==HIGH){
			GPIO_PORTF_DATA_REG |=(1<<pinnumber);
		}
		else if (value==LOW){
			GPIO_PORTF_DATA_REG &=~(1<<pinnumber);
		}
		else{
			/*error*/
		}
		break;
		default:
		break;
	}
}
/*****************************************************************************
* Function Name: GPIO_read
* Purpose      : Read specific PIN (High/Low)
* Parameters   : uint8_t portnumber,uint8_t pinnumber,uint8_t* value
* Return value : void
*****************************************************************************/
void GPIO_read(uint8_t portnumber,uint8_t pinnumber,uint8_t* value){
	switch(portnumber){
		case PORT_F:
		*value=(uint8_t)(GPIO_PORTF_DATA_REG&(1<<pinnumber))>>pinnumber;
		break;
		default:
		break;
	}
}
	
void GPIOF0_Callback(void (*ptrF) (void))
{
	ptrFCallback_PF0 = ptrF;
}

void GPIOF4_Callback(void (*ptrF) (void))
{
	ptrFCallback_PF4 = ptrF;
}

/*External Interrupt handler*/
void GPIOF_Handler()
{
	if(GETBIT(GPIO_PORTF_MIS_REG,0))
	{
		GPIO_PORTF_DATA_REG |= (1<<2); /* Toggle the Red LED at PF2 */
		if (ptrFCallback_PF0 != NULL)
		{
			ptrFCallback_PF0();
		}
		SETBIT(GPIO_PORTF_ICR_REG,0);

	}
	else if (GETBIT(GPIO_PORTF_MIS_REG,4))
	{
		GPIO_PORTF_DATA_REG &= ~(1<<2); /* Toggle the Red LED at PF2 */
		if (ptrFCallback_PF4 != NULL)
		{
			ptrFCallback_PF4();
		}
	  SETBIT(GPIO_PORTF_ICR_REG,4);
	}
}
