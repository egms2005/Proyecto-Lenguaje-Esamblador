bits 64
default rel

global validarMovimiento

section .text

validarMovimiento:
    mov eax, r8d
    imul eax, edx
    add eax, r9d

    movsxd rax, eax

    mov bl, [rcx + rax]

    cmp bl, '#'
    je .bloqueado

    mov eax, 1
    ret

.bloqueado:
    mov eax, 0
    ret