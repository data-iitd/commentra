#include <stdio.h>
#include <stdlib.h>

// Function to read a single line from standard input and strip any trailing whitespace characters.
char* rs() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    // Remove trailing whitespace
    for (int i = strlen(line) - 1; i >= 0 && isspace(line[i]); --i) {
        line[i] = '\0';
    }
    return line;
}

// Function to read an integer from standard input.
int ri() {
    char* line = rs();
    int value = atoi(line);
    free(line);
    return value;
}

// Function to read a list of strings from standard input.
char** rs_() {
    char* line = rs();
    char** tokens = NULL;
    char* token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        tokens = realloc(tokens, (count + 1) * sizeof(char*));
        tokens[count] = token;
        count++;
        token = strtok(NULL, " ");
    }
    free(line);
    return tokens;
}

// Function to read a list of integers from standard input.
int* ri_() {
    char** tokens = rs_();
    int* values = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        values[i] = atoi(tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return values;
}

// Read the integer value of N from standard input.
int N = ri();

// Initialize the variable ans to 0.
int ans = 0;

// Start a loop that iterates from 1 to N + 1.
for (int i = 1; i <= N; i++) {
    // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
    ans += i * (N / i) * (N / i + 1) / 2;
}

// Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
printf("%d\n", ans);

