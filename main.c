#include <stdio.h>
#include "unistd.h"

size_t ft_strlen(const char *str);

int main() {
    const char *message = "Hello, world!";
    size_t length = ft_strlen(message);
    printf("Length of string: %li\n", length);
    return 0;
}

