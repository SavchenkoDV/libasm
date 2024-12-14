global ft_strcpy

ft_strcpy:
    mov rax, rdi
.loop:
    mov al, [rsi]
    mov [rdi], al
    inc rdi
    inc rsi
    cmp al, 0 
    jne .loop
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
