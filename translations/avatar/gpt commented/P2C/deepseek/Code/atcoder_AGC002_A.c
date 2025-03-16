#include <stdio.h>
#include <stdlib.h>

// Function to read a line from standard input and remove trailing whitespace
char* S() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    // Remove trailing whitespace
    for (int i = strlen(line) - 1; i >= 0 && line[i] == ' '; i--) {
        line[i] = '\0';
    }
    return line;
}

// Function to read an integer from standard input
int I() {
    char* line = S();
    return atoi(line);
}

// Function to read a list of integers from standard input
int* LI() {
    char* line = S();
    int* arr = (int*)malloc(sizeof(int) * 10000); // Assuming a maximum of 10000 integers
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    return arr;
}

// Function to read a list of strings from standard input
char** LS() {
    char* line = S();
    char** arr = (char**)malloc(sizeof(char*) * 10000); // Assuming a maximum of 10000 strings
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, " ");
    }
    free(line);
    return arr;
}

int main() {
    int a, b;
    int* input = LI();
    a = input[0];
    b = input[1];
    free(input);

    if (a > 0) {
        printf("Positive\n");
    } else if (a <= 0 && b >= 0) {
        printf("Zero\n");
    } else {
        if ((a + b) % 2 == 0) {
            printf("Negative\n");
        } else {
            printf("Positive\n");
        }
    }

    return 0;
}
