#define RCC_AHB1ENR   (*((unsigned int *) 0x40023830))
#define GPIOD_MODER   (*((unsigned int *) 0x40020C00))
#define GPIOD_ODR     (*((unsigned int *) 0x40020C14))

int main(void) {
    volatile int i;

    RCC_AHB1ENR |= (1U << 3);
    GPIOD_MODER |= (1U << 30);

    while (1) {
        GPIOD_ODR |= (1U << 15);
        for (i = 0; i < 1000000; i++);
        GPIOD_ODR &= ~(1U << 15);
        for (i = 0; i < 1000000; i++);
    }
}