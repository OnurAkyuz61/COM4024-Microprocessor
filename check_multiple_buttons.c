#include "stm32f407xx.h"

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= GPIO_MODER_MODER12_0;
    GPIOA->MODER &= ~(GPIO_MODER_MODER0_Msk | GPIO_MODER_MODER1_Msk);

    while (1) {
        if ((GPIOA->IDR & (GPIO_IDR_ID0 | GPIO_IDR_ID1)) == (GPIO_IDR_ID0 | GPIO_IDR_ID1)) {
            GPIOD->ODR |= GPIO_ODR_OD12;
        } else {
            GPIOD->ODR &= ~GPIO_ODR_OD12;
        }
    }
}