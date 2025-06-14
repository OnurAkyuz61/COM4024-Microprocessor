#include "stm32f407xx.h"

int main(void) {
    volatile int i;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30); // PD12–15 output

    while (1) {
        for (int pin = 12; pin <= 15; pin++) {
            GPIOD->ODR = (1U << pin);
            for (i = 0; i < 300000; i++);
        }
    }
}