.global main

main:
    MOV R0, #5
    MOV R1, #5
    CMP R0, R1
    MOVEQ R2, #100
    MOVNE R2, #200
    B .