.global main

main:
    LDR R0, =0xFF200040    @ Switch address
    LDR R1, [R0]           @ Read switch values into R1

    LDR R2, =0xFF200000    @ LED base address
    STR R1, [R2]           @ Output switch values to LEDs
    B .
