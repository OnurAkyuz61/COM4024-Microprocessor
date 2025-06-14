#include "stm32f407xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOD->MODER &= ~GPIO_MODER_MODER12_Msk;  // temizle
    GPIOD->MODER |= GPIO_MODER_MODER12_1;     // output

    while(1) {
        if (GPIOA->IDR & GPIO_IDR_ID0) {
            GPIOD->ODR |= GPIO_ODR_OD12;      // LED ON
        } else {
            GPIOD->ODR &= ~GPIO_ODR_OD12;     // LED OFF
        }
    }
}