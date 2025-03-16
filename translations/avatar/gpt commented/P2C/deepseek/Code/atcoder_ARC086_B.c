#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to read a line of input and strip the newline character
char* input() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Function to read an integer from input
int read_int() {
    char* line = input();
    return atoi(line);
}

// Function to read a list of integers from input
int* read_ints() {
    char* line = input();
    int* numbers = malloc(sizeof(int) * 100000); // Adjust size as needed
    char* token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    return numbers;
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

// Main function
int main() {
    int N = read_int();
    int* a = read_ints();

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    if (max_sign == 0) {
        printf("0\n");
    } else if (max_sign == 1) {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = 0; i < N - 1; i++) {
            printf("%d %d\n", i + 1, i + 2);
        }
    } else {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = N - 1; i > 0; i--) {
            printf("%d %d\n", i + 1, i);
        }
    }

    free(a);
    return 0;
}
