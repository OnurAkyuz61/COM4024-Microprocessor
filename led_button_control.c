int main(void) {
    volatile unsigned int *RCC = (unsigned int *)0x40023830;
    volatile unsigned int *MODER = (unsigned int *)0x40020C00;
    volatile unsigned int *IDR = (unsigned int *)0x40020C10;
    volatile unsigned int *ODR = (unsigned int *)0x40020C14;

    *RCC |= (1U << 3);         // GPIOD aktif
    *MODER &= ~(3U << 0);      // PD0 input (buton)
    *MODER |= (1U << 30);      // PD15 output (LED)

    while(1) {
        if((*IDR & 0x01) == 0) // Butona basıldıysa (aktif düşük)
            *ODR |= (1U << 15);
        else
            *ODR &= ~(1U << 15);
    }
}