.global main

main:
    LDR R0, =0xFF200050     @ Buton register adresi
    MOV R2, #0              @ Sayaç (buton basılma sayısı)
    MOV R5, #0x01           @ Buton 0 için maske

loop:
    LDR R3, [R0]            @ Buton değerini oku
    TST R3, R5              @ Bit 0 basılı mı?
    BEQ loop                @ Değilse atla
    ADD R2, R2, #1          @ Sayaç ++
wait:
    LDR R3, [R0]
    TST R3, R5
    BNE wait                @ Buton bırakılana kadar bekle
    B loop