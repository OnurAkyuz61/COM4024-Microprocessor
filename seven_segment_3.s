.global main

main:
    LDR R0, =0xFF200020    @ Seven-segment base address
    MOV R1, #0x4F          @ Hex code for digit 3
    STR R1, [R0]           @ Display 3
    B .
