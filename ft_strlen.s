global ft_strlen
extern ft_write

ft_strlen:
    mov rbx, 0       
.loop:
    cmp byte [rdi], 0
    je .done
    inc rdi
    inc rbx
    jmp .loop         
.done:
    mov rax, rbx
    ret

section .note.GNU-stack noalloc noexec nowrite progbits                
