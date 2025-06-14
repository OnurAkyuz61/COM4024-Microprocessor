#include "main.h"

int main(void) {
    int a = 10, b = 20, *p;
    p = &a;
    *p = *p + 1;
    p = &b;
    *p = *p + 1;
}
