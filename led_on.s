.global main

main:
    LDR R0, =0xFF200000    @ LED base address
    MOV R1, #0x01          @ Turn on LED0
    STR R1, [R0]           @ Write to LED register
    B .
