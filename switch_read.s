.global main

main:
    LDR R0, =0xFF200040    @ Switch address
    LDR R1, [R0]           @ Read switch values into R1
    B .
