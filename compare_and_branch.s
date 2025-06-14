.global main

main:
    MOV R0, #5
    MOV R1, #5
    CMP R0, R1          @ Karşılaştır
    MOVEQ R3, #1        @ Eşitse → R3 = 1
    MOVNE R3, #0        @ Değilse → R3 = 0
    B .