.global main

main:
    LDR R0, =0xFF200000    @ LED base address
    MOV R1, #1             @ Bit mask for LED0
    LDR R2, =0x1FFFF       @ Delay value

loop:
    STR R1, [R0]           @ Turn on LED
    BL delay
    MOV R1, #0
    STR R1, [R0]           @ Turn off LED
    BL delay
    MOV R1, #1
    B loop

delay:
    SUBS R2, R2, #1
    BNE delay
    LDR R2, =0x1FFFF
    BX LR
