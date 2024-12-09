global ft_write

ft_write:
    mov rax, 1
    syscall
    cmp rax, -1
    jne .return
    ret 
.return:
    ret
    
