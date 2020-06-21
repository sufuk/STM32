#include "stm32f0xx.h"                  // Device header
void delay(void);
int main(){
	RCC->AHBENR  |= RCC_AHBENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER6_0;
	while(1){		
		GPIOC->BSRR |= GPIO_BSRR_BS_6;
		delay();
		GPIOC->BRR |= GPIO_BRR_BR_6;
		delay();		
	}
}
void delay(){
	int i, j =0;
	for(i=0; i<100000 ; i++){		
		j++;
	}
}
