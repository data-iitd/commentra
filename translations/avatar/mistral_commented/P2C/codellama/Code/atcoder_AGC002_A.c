#include <stdio.h>
#include <stdlib.h>

// Define two helper functions to read input from the standard input stream
int S(  ) {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

int I(  ) {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return atoi(line);
}

// Define another helper function to read a list of integers from the standard input stream
int *LI(  ) {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    char *token = strtok(line, " ");
    int *list = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while (token != NULL) {
        list[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return list;
}

// Define another helper function to read a list of strings from the standard input stream
char **LS(  ) {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    char *token = strtok(line, " ");
    char **list = (char **)malloc(sizeof(char *) * 100);
    int i = 0;
    while (token != NULL) {
        list[i++] = token;
        token = strtok(NULL, " ");
    }
    return list;
}

// Define two variables and initialize them with the values read from the standard input stream
int a, b;
a = I();
b = I();

// Check if 'a' is positive
if (a > 0) {
    // If it is, print the string 'Positive'
    printf("Positive\n");
}

// If 'a' is not positive, check if 'b' is non-negative
else if (a <= 0 && b >= 0) {
    // If it is, print the string 'Zero'
    printf("Zero\n");
}

// If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
else {
    // If it is, print the string 'Negative'
    if ((a + b) % 2 == 0) {
        printf("Negative\n");
    }
    // Otherwise, print the string 'Positive'
    else {
        printf("Positive\n");
    }
}

// End with comment "