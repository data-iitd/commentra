#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to iterate over tokens from standard input
void iterate_tokens(char *token) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) {
        char *word = strtok(line, " ");
        while (word != NULL) {
            strcpy(token, word);
            word = strtok(NULL, " ");
        }
    }
    free(line);
}

// Define a function to solve the problem
void solve(char *S, char *T, int A, int B, char *U) {
    // Check if the first string S matches the string U
    if (strcmp(S, U) == 0) {
        A -= 1;  // Decrement A if S matches U
    }
    // Check if the second string T matches the string U
    if (strcmp(T, U) == 0) {
        B -= 1;  // Decrement B if T matches U
    }
    // Print the final values of A and B
    printf("%d %d\n", A, B);
}

// Define the main function
int main() {
    // Define variables to store the input values
    char S[1000], T[1000], U[1000];
    int A, B;

    // Read the first string S from input
    iterate_tokens(S);
    // Read the second string T from input
    iterate_tokens(T);
    // Read the integer A from input and convert it to an integer
    scanf("%d", &A);
    // Read the integer B from input and convert it to an integer
    scanf("%d", &B);
    // Read the string U from input
    iterate_tokens(U);

    // Call the solve function with the read values
    solve(S, T, A, B, U);

    return 0;
}

