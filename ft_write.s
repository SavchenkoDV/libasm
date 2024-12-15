global ft_write

ft_write:
    mov rax, 1
    syscall
    cmp rax, -1
    jne .error
    ret 
.error:
    
    ret

section .note.GNU-stack noalloc noexec nowrite progbits    
