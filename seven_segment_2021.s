.global main

main:
    LDR R0, =0xFF200020     @ 7 segment base address
    LDR R1, =0x5B3F5B06     @ Display pattern for 2021
    STR R1, [R0]            @ Göstergeye yaz
    B .