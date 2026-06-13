bits 64
default rel

global validarMovimiento
global contarCaracter
global detectarObjeto
global contarCeldasLib
global calcularPuntaje

section .text

validarMovimiento:
    mov eax, r8d
    imul eax, edx
    add eax, r9d

    movsxd rax, eax

    mov r10b, [rcx + rax]

    cmp r10b, '#'
    je .bloqueado

    mov eax, 1
    ret

.bloqueado:
    mov eax, 0
    ret


contarCaracter:
    xor eax, eax
    xor r9d, r9d

.loop_car:
    cmp r9d, edx
    jge .fin_car

    mov r10b, [rcx + r9]

    cmp r10b, r8b
    jne .siguiente

    inc eax

.siguiente:
    inc r9d
    jmp .loop_car

.fin_car:
    ret


detectarObjeto:
    mov eax, r8d
    imul eax, edx
    add eax, r9d

    movsxd rax, eax

    mov r10b, [rcx + rax]

    mov r11b, [rsp + 40]

    cmp r10b, r11b
    je .encontrado

    mov eax, 0
    ret

.encontrado:
    mov eax, 1
    ret


contarCeldasLib:
    xor eax, eax
    xor r8d, r8d

.loop_con:
    cmp r8d, edx
    jge .fin_con

    mov r10b, [rcx + r8]

    cmp r10b, '.'
    jne .siguiente

    inc eax

.siguiente:
    inc r8d
    jmp .loop_con

.fin_con:
    ret

calcularPuntaje:

    mov eax, ecx

    imul eax, 100

    mov r9d, r8d
    imul r9d, 500

    add eax, r9d

    sub eax, edx

    ret