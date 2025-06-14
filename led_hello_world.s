.global main

main:
    LDR R0, =0xFF200000   @ LED base address
    MOV R1, #0x01         @ Sadece LED0 açık
    STR R1, [R0]
    B .