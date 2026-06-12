bits 64
default rel

global validarMovimiento
global contarCaracter
global detectarObjeto

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

contarCaracter:
    xor eax, eax      
    xor r9d, r9d      

.bucle:
    cmp r9d, edx
    jge .fin

    mov bl, [rcx + r9]

    cmp bl, r8b
    jne .siguiente

    inc eax

.siguiente:
    inc r9d
    jmp .bucle

.fin:
    ret

detectarObjeto:
    mov eax, r8d
    imul eax, edx
    add eax, r9d

    movsxd rax, eax

    mov bl, [rcx + rax]

    mov dl, [rsp + 40]

    cmp bl, dl
    je .encontrado

    mov eax, 0
    ret

    .encontrado:
    mov eax, 1
    ret