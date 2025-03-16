#include <stdio.h>

// Function to read a line from standard input and remove trailing whitespace
char* S() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\r\n")] = 0;
    return line;
}

// Function to read an integer from standard input
int I() {
    char* line = NULL;
    int i;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\r\n")] = 0;
    sscanf(line, "%d", &i);
    return i;
}

// Function to read a list of integers from standard input
int* LI() {
    char* line = NULL;
    int* list = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\r\n")] = 0;
    int i, j = 0;
    for (i = 0; i < strlen(line); i++) {
        if (line[i] == ' ') {
            list = realloc(list, (j + 1) * sizeof(int));
            list[j] = atoi(line + j);
            j = i + 1;
        }
    }
    list = realloc(list, (j + 1) * sizeof(int));
    list[j] = atoi(line + j);
    return list;
}

// Function to read a list of strings from standard input
char** LS() {
    char* line = NULL;
    char** list = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\r\n")] = 0;
    int i, j = 0;
    for (i = 0; i < strlen(line); i++) {
        if (line[i] == ' ') {
            list = realloc(list, (j + 1) * sizeof(char*));
            list[j] = malloc(i - j + 2);
            strncpy(list[j], line + j, i - j + 1);
            list[j][i - j + 1] = 0;
            j = i + 1;
        }
    }
    list = realloc(list, (j + 1) * sizeof(char*));
    list[j] = malloc(strlen(line) - j + 2);
    strncpy(list[j], line + j, strlen(line) - j + 1);
    list[j][strlen(line) - j + 1] = 0;
    return list;
}

int main() {
    // Read two integers from input
    int a = I();
    int b = I();

    // Check if the first integer 'a' is positive
    if (a > 0) {
        printf("Positive\n");  // Output 'Positive' if 'a' is greater than 0
    } else if (a <= 0 && b >= 0) {
        printf("Zero\n");  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
    } else {
        // If 'a' is negative and 'b' is also negative
        if ((a + b) % 2 == 0) {
            printf("Negative\n");  // Output 'Negative' if the sum of 'a' and 'b' is even
        } else {
            printf("Positive\n");  // Output 'Positive' if the sum of 'a' and 'b' is odd
        }
    }
    return 0;
}

