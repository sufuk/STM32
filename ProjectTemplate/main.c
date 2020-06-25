#include "stm32f0xx.h"

static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}

int main (void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    GPIOC->MODER |= GPIO_MODER_MODER14_0;
    while (1) {
        GPIOC->BSRR = GPIO_BSRR_BR_14;
        delay(500);
        GPIOC->BSRR = GPIO_BSRR_BS_14;
        delay(500);
    }
    return 0;
}
