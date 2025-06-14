.global main

main:
    MOV R0, #15
    MOV R1, #7
    SUB R2, R0, R1      @ 15 - 7 = 8 → R2
    B .