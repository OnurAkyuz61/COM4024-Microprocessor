#include "stm32f407xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;

    GPIOD->MODER |= GPIO_MODER_MODER15_0;     // PD15 output
    GPIOA->MODER &= ~GPIO_MODER_MODER0_Msk;   // PA0 input

    while (1) {
        if (GPIOA->IDR & GPIO_IDR_ID0) {
            GPIOD->ODR |= GPIO_ODR_OD15;      // LED ON
        } else {
            GPIOD->ODR &= ~GPIO_ODR_OD15;     // LED OFF
        }
    }
}