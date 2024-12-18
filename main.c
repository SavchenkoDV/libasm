#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *restrict dst, const char *restrict src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char*s);

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
            } 

            printf("Test number: %i\n", ++counter);
            printf("   strlen result: %zu\n", strlen(input));
            printf("ft_strlen result: %zu\n", ft_strlen(input));
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
            }

            char std_dest[256] = {0};
            char ft_dest[256] = {0};

            printf("\nTest number: %i\n", ++counter);
            printf("   strcpy result: \"%s\"\n", strcpy(std_dest, input));
            printf("ft_strcpy result: \"%s\"\n", ft_strcpy(ft_dest, input));
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

void write_test() {
    char input[256];
    char fd_input[256];
    int fd;
    int counter = 0;

    printf("\nYou are testing the ft_write function.\n");
    printf("Enter any data to test the function, or type:\n");
    printf("  - \"EXIT\" to quit the program.\n");
    printf("  - \"MENU\" to return to the program menu.\n");

    while (1) {
        printf("\nInput the file descriptor: ");
        if (fgets(fd_input, sizeof(fd_input), stdin)) {
            fd_input[strcspn(fd_input, "\n")] = '\0'; 

            if (strcmp(fd_input, "EXIT") == 0) {
                printf("Exiting the program.\n");
                exit(0);
            } else if (strcmp(fd_input, "MENU") == 0) {
                printf("Returning to the main menu.\n");
                break;
            }

            if (sscanf(fd_input, "%d", &fd) != 1) {
                printf("Invalid file descriptor. Please enter an integer.\n");
                continue;
            }

            printf("Enter the string to write: ");
            if (fgets(input, sizeof(input), stdin)) {
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "EXIT") == 0) {
                    printf("Exiting the program.\n");
                    exit(0);
                } else if (strcmp(input, "MENU") == 0) {
                    printf("Returning to the main menu.\n");
                    break;
                }

                printf("\nTest number: %i\n", ++counter);                
                printf("\n    write result: \n");
                
                errno = 0; 
                ssize_t std_result = write(fd, input, strlen(input));
                int std_errno = errno;

                printf("\n    ft_write result: \n");
                
                errno = 0;
                ssize_t ft_result = ft_write(fd, input, strlen(input));
                int ft_errno = errno;

                printf("\n");

                printf("   write read byte(s): %zd, errno: %d (%s)\n", std_result, std_errno, strerror(std_errno));
                printf("   ft_write read byte(s): %zd, errno: %d (%s)\n", ft_result, ft_errno, strerror(ft_errno));

                printf("\nTesting with an open file descriptor:\n");
                int file_fd = open("test", O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (file_fd < 0) {
                    perror("Failed to open file for testing");
                } else {
                    printf("Opened 'test' for writing.\n\n");
                    
                    errno = 0;
                    std_result = write(file_fd, input, strlen(input));
                    std_errno = errno;

                    printf("   write to file: %zd byte(s), errno: %d (%s)\n", std_result, std_errno, strerror(std_errno));

                    errno = 0;
                    ft_result = ft_write(file_fd, input, strlen(input));
                    ft_errno = errno;

                    printf("   ft_write to file: %zd byte(s), errno: %d (%s)\n", ft_result, ft_errno, strerror(ft_errno));
                    
                    printf("\nFile's name: test\nText written to the file: %s\nThe file is available in the root directory of the project\n", input);
                    close(file_fd);
                    printf("\nClosed 'test'.\n");
                }

            } else {
                printf("Input error. Please try again.\n");
                while (getchar() != '\n');
            }
        } else {
            printf("Input error. Please try again.\n");
            while (getchar() != '\n');
        }

        printf("\n  - \"EXIT\" to quit the program.\n");
        printf("  - \"MENU\" to return to the program menu.\n");
    }
}

void read_test() {
    char buffer[256];
    char buf[256];
    ssize_t result;
    ssize_t std_result;
    size_t bytes_to_read;

    memset(buffer, 0, sizeof(buf));
    memset(buf, 0, sizeof(buf));

    printf("\nYou are testing the ft_read function.\n");

    printf("Enter the number of bytes to read: ");
    if (scanf("%zu", &bytes_to_read) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return;
    }

    printf("\nTesting with stdin (fd = 0). Enter simular text first for read second for ft_read:\n");
    std_result = read(0, buffer, bytes_to_read);
    result = ft_read(0, buf, bytes_to_read);
    int errno_stdin = errno;

    if (std_result >= 0) {
        buffer[std_result] = '\0';
        printf("read result: %s\n", buffer);
    } else {
        printf("read error with stdin: errno = %d (%s)\n", errno_stdin, strerror(errno_stdin));
    }

    if (result >= 0) {
        buffer[result] = '\0';  
        printf("ft_read result: %s\n", buf);
    } else {
        printf("ft_read error with stdin: errno = %d (%s)\n", errno_stdin, strerror(errno_stdin));
    }

    printf("\nTesting with invalid fd (-1):\n");
    std_result = read(-1, buffer, bytes_to_read); 
    result = ft_read(-1, buffer, bytes_to_read);
    int errno_invalid_fd = errno;

    if (std_result >= 0) {
        buffer[std_result] = '\0';
        printf("read with invalid fd: \"%s\"\n", buffer);
    } else {
        printf("read error with invalid fd: errno = %d (%s)\n", errno_invalid_fd, strerror(errno_invalid_fd));
    }

    if (result >= 0) {
        buffer[result] = '\0';
        printf("ft_read with invalid fd: \"%s\"\n", buffer);
    } else {
        printf("ft_read error with invalid fd: errno = %d (%s)\n", errno_invalid_fd, strerror(errno_invalid_fd));
    }

    int file_fd = open("test", O_RDONLY);
    if (file_fd < 0) {
        perror("Failed to open file for testing. Create a file with name \"test\" in the root of the project.");
        return;
    }

    printf("\nTesting with file (fd = %d):\n", file_fd);
    printf("Reading from the file 'test'...\n");

    std_result = read(file_fd, buffer, bytes_to_read);
    result = ft_read(file_fd, buffer, bytes_to_read); 
    int errno_file = errno;

    if (std_result >= 0) {
        buffer[std_result] = '\0';
        printf("Standard read result from file 'test': \"%s\"\n", buffer);
    } else {
        printf("Standard read error with file 'test': errno = %d (%s)\n", errno_file, strerror(errno_file));
    }

    if (result >= 0) {
        buffer[result] = '\0';
        printf("ft_read result from file 'test': \"%s\"\n", buffer);
    } else {
        printf("ft_read error with file 'test': errno = %d (%s)\n", errno_file, strerror(errno_file));
    }

    close(file_fd);
    printf("Closed the test file 'test'.\n");
}

void strdup_test() {
    char input[256];
    int counter = 0;

    printf("\nYou are testing the ft_strdup function.\n");
    printf("Enter any string to test the function, or type:\n");
    printf("  - \"EXIT\" to quit the program.\n");
    printf("  - \"MENU\" to return to the program menu.\n");

    while (1) {
        printf("\nInput string to duplicate: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "EXIT") == 0) {
                printf("Exiting the program.\n");
                exit(0);
            } else if (strcmp(input, "MENU") == 0) {
                printf("Returning to the main menu.\n");
                break;
            }

            printf("\nTest number: %d\n", ++counter);

            // Standard strdup
            char *std_result = strdup(input);
            if (std_result == NULL) {
                perror("   strdup failed");
            } else {
                printf("   strdup result: \"%s\"\n", std_result);
            }

            // Custom ft_strdup
            char *ft_result = ft_strdup(input);
            if (ft_result == NULL) {
                perror("ft_strdup failed");
            } else {
                printf("ft_strdup result: \"%s\"\n", ft_result);
            }

            // Compare results
            if (std_result && ft_result && strcmp(std_result, ft_result) == 0) {
                printf("The results match!\n");
            } else {
                printf("The results do not match.\n");
            }

            // Free memory
            free(std_result);
            free(ft_result);
        } else {
            printf("Input error. Please try again.\n");
        }

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
            }
            if (number == 4) {
                write_test();
            }
            if (number == 5) {
                read_test();
            }
            if (number == 6) {
                strdup_test();
            } else {
                printf("Function %d is not yet implemented.\n", number);
            }
        } else {
            printf("Invalid option. Please select a number between 1 and 6 or 0 to exit.\n");
        }
    }

    return 0;
}

