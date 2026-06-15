bits 64
default rel

global validarMovimiento
global contarCaracter
global detectarObjeto
global contarCeldasLib
global calcularPuntaje

section .text


;Recibe la direccion base del mapa, el 
;numero de columnas, la fila y la columna.
;Devuelve 1 si puede moverse, 0 si hay una
;pared.
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

;Recibe la direccion del mapa, el total 
;de celdas, el caracter a buscar y devuelve
;la cantidad de veces que aparece el caracter
;en el mapa.
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

;Recibe la direccion del mapa, el numero
;de columnas, la fila, la columna y el
;caracter a buscar. Devuelve 1 si el objeto
;esta presente, 0 si no lo esta.
detectarObjeto:
    mov eax, r8d
    imul eax, edx
    add eax, r9d

    movsxd rax, eax

    mov r10b, [rcx + rax]

    mov r11b, [rsp + 40]
    cmp r10b, r11b

    cmp r10b, r11b
    je .encontrado

    mov eax, 0
    ret

.encontrado:
    mov eax, 1
    ret

;Recibe la direccion base del mapa y el
;total de celdas. Devuelve la cantidad de 
;celdas libres ('.').
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

;Calcula el puntaje del jugador al finalizar
;un nivel o el juego, la formula para el puntaje 
;es: (monedas * 100) + (niveles * 500) - pasos
;Recibe las monedas, los pasos realizados hasta el 
;momento y los niveles completados y devuelve el 
;puntaje obtenido.
calcularPuntaje:

    mov eax, ecx

    imul eax, 100

    mov r9d, r8d
    imul r9d, 500

    add eax, r9d

    sub eax, edx

    ret