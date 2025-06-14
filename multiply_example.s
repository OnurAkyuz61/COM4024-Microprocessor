.global main

main:
    MOV R0, #6
    MOV R1, #7
    MUL R2, R0, R1      @ 6 × 7 = 42
    B .