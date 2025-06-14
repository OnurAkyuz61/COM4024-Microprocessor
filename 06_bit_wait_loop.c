#include "main.h"

int main(void) {
    unsigned int A = 0;
    while (!(A & (1 << 10))) {
        // Wait until 10th bit is set
    }
}
