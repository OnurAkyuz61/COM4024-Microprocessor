#include "main.h"
#include <string.h>
#include <stdio.h>

int main(void) {
    int i = 0;
    float x = 1.5;
    char str[20];
    sprintf(str, "i: %d, x: %.2f", i, x);
}
