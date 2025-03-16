#include <stdio.h>
#include <stdlib.h>

// Define two helper functions to read input from the standard input stream
char* S() {
    char* line = (char*)malloc(1000 * sizeof(char));
    fgets(line, 1000, stdin);
    line[strcspn(line, "\n")] = 0; // Remove newline character
    return line;
}

int I() {
    return atoi(S());
}

// Define another helper function to read a list of integers from the standard input stream
int* LI() {
    char* line = S();
    int* arr = (int*)malloc(1000 * sizeof(int));
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    return arr;
}

// Define another helper function to read a list of strings from the standard input stream
char** LS() {
    char* line = S();
    char** arr = (char**)malloc(1000 * sizeof(char*));
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, " ");
    }
    free(line);
    return arr;
}

// Define two variables and initialize them with the values read from the standard input stream
int a, b;
int* input = LI();
a = input[0];
b = input[1];
free(input);

// Check if 'a' is positive
if (a > 0) {
    // If it is, print the string 'Positive'
    printf("Positive\n");

// If 'a' is not positive, check if 'b' is non-negative
} else if (a <= 0 && b >= 0) {
    // If it is, print the string 'Zero'
    printf("Zero\n");

// If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
} else {
    // If it is, print the string 'Negative'
    if ((a + b) % 2 == 0) {
        printf("Negative\n");
    // Otherwise, print the string 'Positive'
    } else {
        printf("Positive\n");
    }
}
