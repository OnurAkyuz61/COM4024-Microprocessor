#include "stm32f407xx.h"

int main(void) {
    volatile int i;

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= GPIO_MODER_MODER12_0;

    while (1) {
        GPIOD->ODR |= GPIO_ODR_OD12;
        for (i = 0; i < 500000; i++);
        GPIOD->ODR &= ~GPIO_ODR_OD12;
        for (i = 0; i < 500000; i++);
    }
}