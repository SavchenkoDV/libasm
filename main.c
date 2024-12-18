#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);


void strlen_test() {
    char    input[BUFFER_SIZE];
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
    char input[BUFFER_SIZE];
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

            char std_dest[BUFFER_SIZE] = {0};
            char ft_dest[BUFFER_SIZE] = {0};

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
    char input_f[BUFFER_SIZE];
    char input_s[BUFFER_SIZE];
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
    char input[BUFFER_SIZE];
    char fd_input[BUFFER_SIZE];
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
    printf("Test 1: Checking stdin started. Input data: \n");
    char buffer_stdin[BUFFER_SIZE];

    ssize_t bytes_read_stdin = ft_read(STDIN_FILENO, buffer_stdin, BUFFER_SIZE - 1);

    printf("ft_read error: %d (%s)\n", errno, strerror(errno));
    buffer_stdin[bytes_read_stdin] = '\0';
    printf("Read %zd bytes.\n", bytes_read_stdin);

    printf("\nTest 2: Reading from the 'test' file started.\n");

    char filename[] = "test";
    int bytes_to_read;
    
    printf("Please create the file 'test' and specify the number of bytes to read: ");
    scanf("%d", &bytes_to_read);

    int fd_std = open(filename, O_RDONLY);
    if (fd_std == -1) {
        printf("Error opening the file for read: %d (%s)\n", errno, strerror(errno));
        exit(0);
    }

    char buffer_read[BUFFER_SIZE];
    ssize_t bytes_read_std_file = read(fd_std, buffer_read, bytes_to_read);
    printf("read error: %d (%s)\n", errno, strerror(errno));
    close(fd_std);

    if (bytes_read_std_file == -1) {
        printf("Error reading using read.\n");
    } else {
        printf("read: Read %zd bytes. Data: %.*s\n", bytes_read_std_file, (int)bytes_read_std_file, buffer_read);
    }

    int fd_ft = open(filename, O_RDONLY);
    if (fd_ft == -1) {
        printf("Error opening the file for read: %d (%s)\n", errno, strerror(errno));
        exit(0);
    }

    char buffer_ft_read[BUFFER_SIZE];
    ssize_t bytes_read_ft_file = ft_read(fd_ft, buffer_ft_read, bytes_to_read);
    printf("ft_read: %d (%s)\n", errno, strerror(errno));
    close(fd_ft);

    if (bytes_read_ft_file == -1) {
        printf("Error opening the file for ft_read: %d (%s)\n", errno, strerror(errno));
    } else {
        printf("ft_read: Read %zd bytes. Data: %.*s\n", bytes_read_ft_file, (int)bytes_read_ft_file, buffer_ft_read);
    }

        printf("\nTest 3: Checking invalid file descriptor started.\n");

    int invalid_fd = -1;
    
    char buffer_invalid[BUFFER_SIZE];

    ssize_t bytes_read_ft_invalid = ft_read(invalid_fd, buffer_invalid, BUFFER_SIZE - 1);
    printf("ft_read error: %d (%s)\n", errno, strerror(errno));
    ssize_t bytes_read_std_invalid = read(invalid_fd, buffer_invalid, BUFFER_SIZE - 1);
    printf("read error: %d (%s)\n", errno, strerror(errno));

    if (bytes_read_ft_invalid == bytes_read_std_invalid) {
        printf("ft_read and read results match.\n");
    } else {
        printf("ft_read and read results do not match.\n");
    }

    exit(0);
}

void strdup_test() {
    char input[BUFFER_SIZE];
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

            char *std_result = strdup(input);
            if (std_result == NULL) {
                perror("   strdup failed");
            } else {
                printf("   strdup result: \"%s\"\n", std_result);
            }

            char *ft_result = ft_strdup(input);
            if (ft_result == NULL) {
                perror("ft_strdup failed");
            } else {
                printf("ft_strdup result: \"%s\"\n", ft_result);
            }

            if (std_result && ft_result && strcmp(std_result, ft_result) == 0) {
                printf("The results match!\n");
            } else {
                printf("The results do not match.\n");
            }

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

