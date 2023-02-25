/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_HW
 *       Module:  -
 *
 *  Description:  TM4C123GH6PM Register file     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile unsigned long *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_MIS_REG        (*((volatile unsigned long *)0x40025418))
#define GPIO_PORTF_ICR_REG        (*((volatile unsigned long *)0x4002541C))



#define SYSCTL_REGCGC2_REG        (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGCGPIO_REG       (*((volatile unsigned long *)0x400FE608))

/*****************************************************************************
Systick Timer Registers
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile unsigned long *)0xE000E018))

/*****************************************************************************
PLL Registers
*****************************************************************************/
#define SYSCTL_RIS_REG            (*((volatile unsigned long *)0x400FE050))
#define SYSCTL_RCC_REG            (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC2_REG           (*((volatile unsigned long *)0x400FE070))

/*****************************************************************************
NVIC Registers
*****************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))

#define NVIC_PRI0_REG             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_REG             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_REG             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_REG             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_REG             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_REG             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_REG             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_REG             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_REG             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_REG             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_REG            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_REG            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_REG            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_REG            (*((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_REG            (*((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_REG            (*((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_REG            (*((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_REG            (*((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_REG            (*((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_REG            (*((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_REG            (*((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_REG            (*((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_REG            (*((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_REG            (*((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_REG            (*((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_REG            (*((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_REG            (*((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_REG            (*((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_REG            (*((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_REG            (*((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_REG            (*((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_REG            (*((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_REG            (*((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_REG            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile unsigned long *)0xE000E488))

#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile unsigned long *)0xE000E110))
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile unsigned long *)0xE000E190))

/*****************************************************************************
SCB Registers
*****************************************************************************/
#define NVIC_SYSTEM_PRI1_REG      (*((volatile unsigned long *)0xE000ED18))
#define NVIC_SYSTEM_PRI2_REG      (*((volatile unsigned long *)0xE000ED1C))
#define NVIC_SYSTEM_PRI3_REG      (*((volatile unsigned long *)0xE000ED20))
#define NVIC_SYSTEM_SYSHNDCTRL    (*((volatile unsigned long *)0xE000ED24))
#define NVIC_SYSTEM_INTCTRL       (*((volatile unsigned long *)0xE000ED04))
#define NVIC_SYSTEM_CFGCTRL       (*((volatile unsigned long *)0xE000ED14))


#endif  /* MCU_HW */

/**********************************************************************************************************************
 *  END OF FILE: MCU_HW.h
 *********************************************************************************************************************/
