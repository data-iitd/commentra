#include <stdio.h>
#include <stdlib.h>

// Define a function named 'solve' that takes five arguments: S, T, A, B, and U.
void solve(char *S, char *T, int A, int B, char *U) {

    // Check if S is equal to U. If yes, decrement A.
    if (strcmp(S, U) == 0) {
        A -= 1;
    }

    // Check if T is equal to U. If yes, decrement B.
    if (strcmp(T, U) == 0) {
        B -= 1;
    }

    // Print the updated values of A and B.
    printf("%d %d\n", A, B);

    // Return from the function.
    return;
}

// Define a function named 'main' that doesn't take any arguments.
int main() {

    // Define an inner function named 'iterate_tokens' that generates tokens from the standard input.
    char *iterate_tokens() {
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        while ((read = getline(&line, &len, stdin)) != -1) {
            char *token = strtok(line, " ");
            while (token != NULL) {
                yield token;
                token = strtok(NULL, " ");
            }
        }
        free(line);
    }

    // Assign the next token to variables S, T, A, B, and U.
    char *S = iterate_tokens();
    char *T = iterate_tokens();
    int A = atoi(iterate_tokens());
    int B = atoi(iterate_tokens());
    char *U = iterate_tokens();

    // Call the 'solve' function with the assigned variables.
    solve(S, T, A, B, U);

    // Return from the function.
    return 0;
}

// If the script is run as the main program, execute the 'main' function.
int main(int argc, char *argv[]) {
    return main();
}

