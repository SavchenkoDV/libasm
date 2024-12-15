global ft_strcmp

ft_strcmp:
.loop:
    mov al, [rdi]
    mov bl, [rsi]
    cmp al, 0
    je .return
    cmp al, bl           
    jne .return                        
    inc rdi                
    inc rsi               
    jmp .loop              

.return:
    sub al, bl
    movsx rax, al                        
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
