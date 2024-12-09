global ft_strlen

ft_strlen:
    mov rcx, 0       
.loop:
    cmp byte [rdi], 0
    je .done
    inc rdi           
    inc rcx                       
    jmp .loop         
.done:
    mov rax, rcx
    ret

section .note.GNU-stack noalloc noexec nowrite progbits                
