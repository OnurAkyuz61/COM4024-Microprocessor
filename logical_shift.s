.global main

main:
    MOV R0, #0x1        @ R0 = 0x00000001
    LSL R1, R0, #3      @ R1 = R0 << 3 → 8
    LSR R2, R1, #2      @ R2 = R1 >> 2 → 2
    B .