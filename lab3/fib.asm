; fib.asm
default rel

extern scanf
extern printf

section .data
prompt_msg db "Введіть номер числа Фібоначчі (0-93): ", 0
format_in  db "%d", 0
result_msg db "Число Фібоначчі №%d дорівнює %llu", 10, 0

section .bss
input_n    resq 1

section .text
global main

fibonacci:
    push rbp
    mov  rbp, rsp
    push rbx

    cmp  edi, 0
    je   .return_0
    cmp  edi, 1
    je   .return_1

    push rdi
    sub  edi, 1
    call fibonacci
    mov  rbx, rax

    pop  rdi
    sub  edi, 2
    call fibonacci

    add  rax, rbx
    jmp  .end

.return_0:
    xor  eax, eax
    jmp  .end

.return_1:
    mov  eax, 1

.end:
    pop  rbx
    mov  rsp, rbp
    pop  rbp
    ret

main:
    push rbp
    mov  rbp, rsp

    lea  rdi, [prompt_msg]
    xor  eax, eax
    call printf

    lea  rdi, [format_in]
    lea  rsi, [input_n]
    xor  eax, eax
    call scanf

    mov  rdi, [input_n]
    call fibonacci

    lea  rdi, [result_msg]
    mov  rsi, [input_n]
    mov  rdx, rax
    xor  eax, eax
    call printf

    xor  eax, eax
    leave
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
