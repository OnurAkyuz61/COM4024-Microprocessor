#include "main.h"
#define GPIO_MODER (*((int *)0x40020400))

int main(void) {
    int v;
    v = GPIO_MODER;
}
