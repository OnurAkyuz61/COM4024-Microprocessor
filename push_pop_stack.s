.global main

main:
    MOV R4, #0x55AA55AA
    PUSH {R4}           @ Stack'e R4'ü at
    POP {R5}            @ Stack'ten al → R5
    B .