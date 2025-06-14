#include "stm32f407xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIODEN;

    GPIOD->MODER &= ~GPIO_MODER_MODER12_Msk;
    GPIOD->MODER |= GPIO_MODER_MODER12_0;   // PD12 output
    GPIOA->MODER &= ~GPIO_MODER_MODER0_Msk; // PA0 input

    while (1) {
        if ((GPIOA->IDR & GPIO_IDR_ID0) == GPIO_IDR_ID0) {
            GPIOD->ODR |= GPIO_ODR_OD12;    // LED ON
        } else {
            GPIOD->ODR &= ~GPIO_ODR_OD12;   // LED OFF
        }
    }
}