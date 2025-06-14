#include "stm32f4xx.h"

static void wait(void) {
    for (volatile int i = 0; i < 1000000; i++);
}

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // Set PD12–15 as output
    GPIOD->MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);

    while (1) {
        GPIOD->ODR |= GPIO_ODR_OD12;
        wait();
        GPIOD->ODR &= ~GPIO_ODR_OD12;
        wait();

        GPIOD->ODR |= GPIO_ODR_OD13;
        wait();
        GPIOD->ODR &= ~GPIO_ODR_OD13;
        wait();

        GPIOD->ODR |= GPIO_ODR_OD14;
        wait();
        GPIOD->ODR &= ~GPIO_ODR_OD14;
        wait();

        GPIOD->ODR |= GPIO_ODR_OD15;
        wait();
        GPIOD->ODR &= ~GPIO_ODR_OD15;
        wait();
    }
}