#include <stdio.h>
#include <stdlib.h>

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
char* rs() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Function to read a single integer from standard input
int ri() {
    char* line = rs();
    return atoi(line);
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
int* ri_() {
    char* line = rs();
    int* numbers = NULL;
    char* token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        numbers = realloc(numbers, (count + 1) * sizeof(int));
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    return numbers;
}

int main() {
    // Read the number of test cases from standard input
    int N = ri();

    // Initialize the answer to 0
    long long ans = 0;

    // Iterate through all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        // Calculate the contribution of i to the answer
        // The formula is given by the problem statement
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the answer
    printf("%lld\n", ans);

    return 0;
}
