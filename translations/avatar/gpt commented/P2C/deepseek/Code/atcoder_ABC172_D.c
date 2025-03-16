#include <stdio.h>

// Function to read a line from standard input and remove trailing whitespace
char* rs() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    // Remove trailing whitespace
    for (int i = strlen(line) - 1; i >= 0 && line[i] == ' ' || line[i] == '\n' || line[i] == '\r'; --i) {
        line[i] = '\0';
    }
    return line;
}

// Function to read an integer from standard input
int ri() {
    char* line = rs();
    return atoi(line);
}

// Function to read a line from standard input and return a list of strings
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
    tokens = realloc(tokens, (count + 1) * sizeof(char*));
    tokens[count] = NULL;
    free(line);
    return tokens;
}

// Function to read a line from standard input and return a list of integers
int* ri_() {
    char** tokens = rs_();
    int* numbers = malloc((strlen(tokens[0]) + 1) * sizeof(int));
    int count = 0;
    for (char** p = tokens; *p != NULL; p++) {
        numbers[count++] = atoi(*p);
    }
    free(tokens);
    return numbers;
}

// Read the integer N from input
int N = ri();

// Initialize the answer variable to accumulate the result
long long ans = 0;

// Loop through each integer from 1 to N (inclusive)
for (int i = 1; i <= N; i++) {
    // Calculate the contribution of the current integer i to the answer
    ans += (long long)i * (N / i) * ((N / i) + 1) / 2;
}

// Print the final result
printf("%lld\n", ans);

