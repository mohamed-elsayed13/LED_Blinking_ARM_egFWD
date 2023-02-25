#ifndef GPIO_PROGRAM_H_
#define GPIO_PROGRAM_H_

/*****************************************************************************
*
* INCLUDES
*
*****************************************************************************/
#include "Mcu_Hw.h"
#include "Platform_Types.h"
/*****************************************************************************
*
* Macros
*
*****************************************************************************/
#define NULL (void *)0

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
#define PORT_E 'E'
#define PORT_F 'F'
/*Direction defines*/
#define  IN 0
#define  OUT 1
/*value defines*/
#define  LOW 0
#define  HIGH 1

/*****************************************************************************
*
* Datatypes
*
*****************************************************************************/

static void (*ptrFCallback_PF4) (void) = NULL;
static void (*ptrFCallback_PF0) (void) = NULL;



#endif /* GPIO_PROGRAM_H_ */
