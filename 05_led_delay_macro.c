#include "stm32f407xx.h"

void delay(int time) {
    for (volatile int i = 0; i < time; i++);
}

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= GPIO_MODER_MODER13_0;

    while (1) {
        GPIOD->ODR |= GPIO_ODR_OD13;
        delay(500000);
        GPIOD->ODR &= ~GPIO_ODR_OD13;
        delay(500000);
    }
}