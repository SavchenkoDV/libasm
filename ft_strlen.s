global ft_strlen

ft_strlen:
    xor rax, rax       
.loop:
    cmp byte [rdi], 0
    je .done
    inc rdi
    inc rax
    jmp .loop         
.done:
    ret

section .note.GNU-stack noalloc noexec nowrite progbits                
