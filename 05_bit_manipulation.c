#include "main.h"

int main(void) {
    unsigned int A, B;
    A = 0x80F7035C;
    A = A | (1U << 11U);        // Set bit 11
    A = A & ~(1U << 17U);       // Clear bit 17
    A = A ^ (1U << 12U);        // Toggle bit 12
    A = A ^ (1U << 8U);         // Toggle bit 8
    B = (A & (1U << 9U)) != 0;  // Test bit 9
    B = (A & (1U << 10U)) != 0; // Test bit 10
    if (A & (1U << 9U)) {
        // Do something
    }
}
