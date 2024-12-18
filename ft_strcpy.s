global ft_strcpy

ft_strcpy:
    mov rax, rdi
.loop:
    mov bl, [rsi]
    mov [rdi], bl
    inc rdi
    inc rsi
    cmp bl, 0 
    jne .loop
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
