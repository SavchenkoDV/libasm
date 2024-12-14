#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *restrict dst, const char *restrict src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

void strlen_test() {
    char    input[256];
    int     counter = 0;

    printf("\nYou are testing the ft_strlen function.\n");
    printf("Enter any data to test the function, or type:\n");
    printf("  - \"EXIT\" to quit the program.\n");
    printf("  - \"MENU\" to return to the program menu.\n");

    while (1) {        
        printf("\nInput: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "EXIT") == 0) {
                printf("Exiting the program.\n");
                exit(0);
            } else if (strcmp(input, "MENU") == 0) {
                printf("Returning to the main menu.\n");
                break;
            } else if (input[0] == '\0') {
                printf("Empty input. Please enter some data.\n");
            } else {
                printf("Test number: %i\n", ++counter);
                printf("   strlen result: %zu\n", strlen(input));
                printf("ft_strlen result: %zu\n", ft_strlen(input));
            }
        } else {
            printf("Input error. Please try again.\n");
        }
    printf("\n  - \"EXIT\" to quit the program.\n");
    printf("  - \"MENU\" to return to the program menu.\n");
    }
}

void strcpy_test() {
    char input[256];
    int counter = 0;

    printf("\nYou are testing the ft_strcpy function.\n");
    printf("Enter any string to test the function, or type:\n");
    printf("  - \"EXIT\" to quit the program.\n");
    printf("  - \"MENU\" to return to the program menu.\n");

    while (1) {
        printf("\nInput string to copy: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "EXIT") == 0) {
                printf("Exiting the program.\n");
                exit(0);
            } else if (strcmp(input, "MENU") == 0) {
                printf("Returning to the main menu.\n");
                break;
            } else if (input[0] == '\0') {
                printf("Empty input. Please enter some data.\n");
            } else {
                char std_dest[256] = {0};
                char ft_dest[256] = {0};

                printf("\nTest number: %i\n", ++counter);
                printf("   strcpy result: \"%s\"\n", strcpy(std_dest, input));
                printf("ft_strcpy result: \"%s\"\n", ft_strcpy(ft_dest, input));
                
            }
        } else {
            printf("Input error. Please try again.\n");
        }

        printf("\n  - \"EXIT\" to quit the program.\n");
        printf("  - \"MENU\" to return to the program menu.\n");
    }
}


void strcmp_test() {
    char input_f[256];
    char input_s[256];
    int counter = 0;

    printf("\nYou are testing the ft_strcmp function.\n");
    printf("Enter two strings to test the function, or type:\n");
    printf("  - \"EXIT\" to quit the program.\n");
    printf("  - \"MENU\" to return to the program menu.\n");

    while (1) {        
        printf("\nInput first string: ");
        if (!fgets(input_f, sizeof(input_f), stdin)) {
            printf("Input error. Please try again.\n");
            continue;
        }
        input_f[strcspn(input_f, "\n")] = '\0'; 

        if (strcmp(input_f, "EXIT") == 0) {
            printf("Exiting the program.\n");
            exit(0);
        } else if (strcmp(input_f, "MENU") == 0) {
            printf("Returning to the main menu.\n");
            break;
        }

        printf("Input second string: ");
        if (!fgets(input_s, sizeof(input_s), stdin)) {
            printf("Input error. Please try again.\n");
            continue;
        }
        input_s[strcspn(input_s, "\n")] = '\0';

        if (strcmp(input_s, "EXIT") == 0 || strcmp(input_s, "MENU") == 0) {
            printf("Invalid input. Please enter valid strings for comparison.\n");
            continue;
        }

        printf("\nTest number: %i\n", ++counter);
        printf("   strcmp result: %d\n", strcmp(input_f, input_s));
        printf("ft_strcmp result: %d\n", ft_strcmp(input_f, input_s));

        printf("\n  - \"EXIT\" to quit the program.\n");
        printf("  - \"MENU\" to return to the program menu.\n");
    }
}

int main() {
    int number = -1;

    while (1) {
        printf("\nEnter the number of the function you want to test (1-6) or 0 to exit:\n");
        printf(" 1. ft_strlen\n");
        printf(" 2. ft_strcpy\n");
        printf(" 3. ft_strcmp\n");
        printf(" 4. ft_write\n");
        printf(" 5. ft_read\n");
        printf(" 6. ft_strdup\n");
        printf("Input: ");

        if (scanf("%d", &number) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        if (number == 0) {
            printf("Exiting the program.\n");
            break;
        }

        if (number > 0 && number <= 6) {
            printf("You selected function %d.\n", number);
            if (number == 1) {
                strlen_test();
            }
            if (number == 2) {
                strcpy_test();
            }
            if (number == 3) {
                strcmp_test();
            } else {
                printf("Function %d is not yet implemented.\n", number);
            }
        } else {
            printf("Invalid option. Please select a number between 1 and 6 or 0 to exit.\n");
        }
    }

    return 0;
}
