.global main

main:
    LDR R0, =0xFF200020     @ HEX display adresi
    LDR R1, =0x5B3F5B06     @ 2 0 2 1 için kodlar (little endian!)
    STR R1, [R0]
    B .