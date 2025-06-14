#include "stm32f4xx.h"

int main(void) {
    volatile int i;

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= GPIO_MODER_MODER15_0;         // PD15 = output
    GPIOA->MODER &= ~GPIO_MODER_MODER0_Msk;       // PA0 = input

    while (1) {
        if (GPIOA->IDR & GPIO_IDR_ID0) {
            GPIOD->ODR |= GPIO_ODR_OD15;
        } else {
            GPIOD->ODR &= ~GPIO_ODR_OD15;
        }
        for (i = 0; i < 1000000; i++);
    }
}