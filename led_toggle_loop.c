int main(void) {
    volatile int i;
    volatile unsigned int *RCC = (unsigned int *)0x40023830;
    volatile unsigned int *MODER = (unsigned int *)0x40020C00;
    volatile unsigned int *ODR = (unsigned int *)0x40020C14;

    *RCC |= (1U << 3);
    *MODER |= (1U << 30);

    while(1) {
        *ODR ^= (1U << 15);    // XOR: toggle PD15
        for(i = 0; i < 1000000; i++);
    }
}