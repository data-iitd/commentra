
#include <stdio.h>

// Define a function named'solve' that takes five arguments: S, T, A, B, and U.
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

// Define a function named'main' that doesn't take any arguments.
int main() {

    // Define variables S, T, A, B, and U.
    char S[100];
    char T[100];
    int A;
    int B;
    char U[100];

    // Read input from standard input and assign it to the variables S, T, A, B, and U.
    scanf("%s %s %d %d %s", S, T, &A, &B, U);

    // Call the'solve' function with the assigned variables.
    solve(S, T, A, B, U);

    // Return from the function.
    return 0;
}

// End of code.
