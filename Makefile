NAME = libasm.a

ASM_SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
C_SRC = main.c
ASM_OBJ = $(ASM_SRC:.s=.o)
C_OBJ = $(C_SRC:.c=.o)

CC = gcc
ASM = nasm
ASM_FLAGS = -f elf64
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(ASM_OBJ)
	$(AR) $(NAME) $(ASM_OBJ)

%.o: %.s
	$(ASM) $(ASM_FLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(C_OBJ)
	$(CC) $(CFLAGS) -o libasm $(C_OBJ) $(NAME)

clean:
	rm -f $(ASM_OBJ) $(C_OBJ)

fclean: clean
	rm -f $(NAME) libasm

re: fclean all

