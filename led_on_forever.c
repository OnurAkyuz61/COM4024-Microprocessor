int main(void) {
    volatile unsigned int *RCC = (unsigned int *)0x40023830;
    volatile unsigned int *MODER = (unsigned int *)0x40020C00;
    volatile unsigned int *ODR = (unsigned int *)0x40020C14;

    *RCC |= (1U << 3);         // GPIOD clock
    *MODER |= (1U << 30);      // PD15 output
    *ODR |= (1U << 15);        // LED ON

    while(1);                  // sonsuz döngü
}