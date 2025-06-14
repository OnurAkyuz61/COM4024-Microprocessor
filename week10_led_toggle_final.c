int main(void) {
    volatile int i;
    volatile unsigned int RCC_AHB1ENR_adr = 0x40023830;
    volatile unsigned int GPIOD_MODER_adr = 0x40020C00;
    volatile unsigned int GPIOD_ODR_adr   = 0x40020C14;

    volatile unsigned int *RCC_AHB1ENR;
    volatile unsigned int *GPIOD_MODER;
    volatile unsigned int *GPIOD_ODR;

    RCC_AHB1ENR = (unsigned int *) RCC_AHB1ENR_adr;
    *RCC_AHB1ENR |= (1U << 3);       // GPIOD aktif

    GPIOD_MODER = (unsigned int *) GPIOD_MODER_adr;
    *GPIOD_MODER |= (1U << 30);      // PD15 output

    GPIOD_ODR = (unsigned int *) GPIOD_ODR_adr;

    while(1) {
        *GPIOD_ODR |= (1U << 15);    // LED ON
        for(i = 0; i < 1000000; i++);
        *GPIOD_ODR &= ~(1U << 15);   // LED OFF
        for(i = 0; i < 1000000; i++);
    }
}