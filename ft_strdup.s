extern 		__errno_location
extern		malloc
extern		ft_strlen
extern		ft_strcpy

global		ft_strdup

ft_strdup:
    mov     rbx, rdi
	
    call	ft_strlen		
	inc		rax				
	
    mov		rdi, rax		
	call	malloc	wrt ..plt
	cmp		rax, 0			
	je		.error			
   
    mov     rdi, rax
    mov     rsi, rbx
    call    ft_strcpy
    ret

.error:
	call	__errno_location wrt ..plt
	mov     rbx, 12
    mov		[rax], rbx			
	xor		rax, rax		    
	ret							

section .note.GNU-stack noalloc noexec nowrite progbits
