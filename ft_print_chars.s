global ft_print_chars

section .data
    newline db 10      ; символ новой строки

section .text

ft_print_chars:
    mov rax, 0         ; rax используется как индекс
.loop:
    ; Проверяем конец строки
    cmp byte [rdi + rax], 0
    je .done           ; если символ равен 0, выходим из цикла

    ; Выводим текущий символ
    mov rsi, rdi       ; rsi указывает на начало строки
    add rsi, rax       ; добавляем индекс для получения текущего символа
    mov rdx, 1         ; длина для write = 1 (только текущий символ)

    mov rax, 1         ; sys_write
    mov rdi, 1         ; дескриптор stdout
    syscall            ; выполняем системный вызов

    inc rax            ; переходим к следующему символу
    jmp .loop          ; повторяем цикл
.done:
    ; Добавляем новую строку
    mov rsi, newline   ; указываем на символ новой строки
    mov rdx, 1         ; длина для write = 1
    mov rax, 1         ; sys_write
    mov rdi, 1         ; дескриптор stdout
    syscall            ; выполняем системный вызов

    ret

section .note.GNU-stack noalloc noexec nowrite progbits 
