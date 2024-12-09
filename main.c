#include <stdio.h>
#include "unistd.h"

size_t ft_strlen(const char *str);
void ft_print_chars(const char *str);


int main() {
    const char *message = "Hello, world!";
    size_t length = ft_strlen(message);
    ft_print_chars(message);
    printf("\nLength of string: %zu\n", length);
    return 0;
}

