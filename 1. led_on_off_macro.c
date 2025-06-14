#include "stm32f4xx.h"

int main(void) {
    volatile int i;

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;           // GPIOD clock enable
    GPIOD->MODER |= GPIO_MODER_MODER15_0;          // PD15 = output

    while (1) {
        GPIOD->ODR |= GPIO_ODR_OD15;               // LED ON
        for (i = 0; i < 1000000; i++);
        GPIOD->ODR &= ~GPIO_ODR_OD15;              // LED OFF
        for (i = 0; i < 1000000; i++);
    }
}