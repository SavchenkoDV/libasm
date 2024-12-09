global ft_strlen

ft_strlen:
    mov rax, 0       
.loop:
    cmp byte [rdi + rax], 0
    je .done           
    inc rax                       
    jmp .loop         
.done:
    ret

section .note.GNU-stack noalloc noexec nowrite progbits                
