#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*****************************************************************************
*
* INCLUDES
*
*****************************************************************************/
#include "GPIO_PRIVATE.h"
#include "GPIO_Config.h"

/*****************************************************************************
*
* GPIO DRIVER PROTOTYPES
*
*****************************************************************************/
 /*Initialize GPIO direction*/
void GPIO_init(uint8_t portnumber,uint8_t pinnumber,uint8_t direction); 
/*write data to GPIO*/
void GPIO_write(uint8_t portnumber,uint8_t pinnumber,uint8_t value); 
/*Read GPIO*/
void GPIO_read(uint8_t portnumber,uint8_t pinnumber,uint8_t* value);

void GPIOF0_Callback(void (*ptrF) (void));

void GPIOF4_Callback(void (*ptrF) (void));

#endif /* GPIO_INTERFACE_H */
