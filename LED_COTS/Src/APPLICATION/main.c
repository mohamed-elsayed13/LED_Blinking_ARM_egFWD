#include "NVIC_Interface.h"
#include "LED.h"
#include "SYSTICK_Interface.h"

uint8_t Time_on=5,Time_off=2;

void systick_ISR(void);
void PF0_ISR(void);
void PF4_ISR(void);
static uint8_t ticks=0;
int main(void){
	SysTick_Callback(systick_ISR);
	GPIOF4_Callback(PF4_ISR);
	GPIOF0_Callback(PF0_ISR);		
	
	GPIO_init(PORT_F,0,IN);
	GPIO_init(PORT_F,4,IN);
	NVIC_EnableINT(NVIC_GPIOF);
	NVIC_EnableINT(NVIC_SYSTICK);
	LED_init(PORT_F,2);
	LED_on(PORT_F,2);
	SysTick_Init(15999999);
	SysTick_Enable();
}
void systick_ISR(void){
	if(ticks<Time_on){
		LED_on(PORT_F,2);
		ticks++;
	}
	else if((ticks>=Time_on) && (ticks <(Time_off+Time_on))){
		LED_off(PORT_F,2);
		ticks++;
	}
	else {
		ticks=0;
	}
}
void PF0_ISR(void){
	Time_on++;
}
void PF4_ISR(void){
	Time_off++;
}
