#include "stm32f407xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER &= ~GPIO_MODER_MODER14_Msk;
    GPIOD->MODER |= GPIO_MODER_MODER14_0;  // PD14 output

    while (1) {
        GPIOD->ODR ^= GPIO_ODR_OD14;
        for (volatile int i = 0; i < 800000; i++);
    }
}