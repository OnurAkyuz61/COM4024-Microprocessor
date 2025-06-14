#include "stm32f4xx.h"

static void wait(void) {
    for (volatile int i = 0; i < 1000000; i++);
}

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // PD12–15 output
    for (int pin = 12; pin <= 15; pin++) {
        GPIOD->MODER |= (1 << (pin * 2));
    }

    while (1) {
        for (int pin = 12; pin <= 15; pin++) {
            GPIOD->ODR |= (1 << pin);
            wait();
            GPIOD->ODR &= ~(1 << pin);
            wait();
        }
    }
}