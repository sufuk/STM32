#include "..\Drivers\CMSIS\STM32F0xx\inc\stm32f0xx.h"
// Quick and dirty delay
static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}
int main (void) {
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;   // Turn on the GPIOC peripheral
    GPIOC->MODER |= GPIO_MODER_MODER13_0;     // Put pin 13 in general purpose output mode
    while (1) {
        GPIOC->BSRR = GPIO_BSRR_BR_13;         // Reset the state of pin 13 to output low
        delay(500);
        GPIOC->BSRR = GPIO_BSRR_BS_13;         // Set the state of pin 13 to output high
        delay(500);
    }
    return 0;
}
