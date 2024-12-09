NAME = test_strlen

ASM_SRC = ft_strlen.s ft_print_chars.s
C_SRC = main.c
ASM_OBJ = $(ASM_SRC:.s=.o)
C_OBJ = $(C_SRC:.c=.o)

CC = gcc
ASM = nasm
ASM_FLAGS = -f elf64
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(ASM_OBJ) $(C_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(ASM_OBJ) $(C_OBJ)

%.o: %.s
	$(ASM) $(ASM_FLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ASM_OBJ) $(C_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

