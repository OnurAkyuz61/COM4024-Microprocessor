.global main

main:
    LDR R0, =0xFF200040     @ Switch adresi
    LDR R1, [R0]             @ Switch durumu → R1
    LDR R2, =0xFF200000     @ LED adresi
    STR R1, [R2]             @ Switch → LED
    B .