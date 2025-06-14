#include "stm32f407xx.h"

void delay(int time) {
    for (volatile int i = 0; i < time; i++);
}

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= GPIO_MODER_MODER12_0;
    GPIOA->MODER &= ~GPIO_MODER_MODER0_Msk;

    while (1) {
        if ((GPIOA->IDR & GPIO_IDR_ID0) == 0) {
            GPIOD->ODR |= GPIO_ODR_OD12;
            delay(4000000);  // uzun delay
            GPIOD->ODR &= ~GPIO_ODR_OD12;
        }
    }
}