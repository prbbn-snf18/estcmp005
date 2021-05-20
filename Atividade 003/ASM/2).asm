; 2) Faça um Programa que peça dois números e imprima o maior deles.
section .bss
    num1 resb 5
    num2 resb 5
    aux1 resb 5
    aux2 resb 5
section .text
  global _start     ;início do programa

_start:

    ;Mostra a mensagem para o usuario
    mov edx, len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80

    ;Recebe o primeiro valor
    mov eax, 3
    mov ebx, 2
    mov ecx, num1
    mov edx, 5
    int 0x80

    ;Recebe o segundo valor
    mov eax, 3
    mov ebx, 2
    mov ecx, num2
    mov edx, 5
    int 0x80

    ;Calculo
    mov eax, num1
    mov ebx, num2
    sub ebx, eax
    cmp ebx, 00
    jge RES2
    
    ;Exibe se for o primeiro numero
    mov ecx, eax    ;Numero pra ser mostrado
    mov eax, 4
    mov ebx, 1
    mov edx, 5
    int 0x80
    jmp FIN         ;Pula pro final sem fazer o bloco abaixo

    ;Exibe se for o segundo
RES2:
    mov ecx, ebx
    mov eax, 4
    mov ebx, 1
    mov edx, 5
    int 0x80

    ;finaliza o programa
FIN:
    mov eax, 1
    int 0x80

section .data
    msg db 'Digite dois números: ', 0xa
    len equ $ - msg