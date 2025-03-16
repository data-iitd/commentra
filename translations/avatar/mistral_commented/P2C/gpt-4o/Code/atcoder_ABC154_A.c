#include <stdio.h>
#include <string.h>

void solve(char *S, char *T, int A, int B, char *U) {
    // Check if S is equal to U. If yes, decrement A.
    if (strcmp(S, U) == 0) {
        A--;
    }

    // Check if T is equal to U. If yes, decrement B.
    if (strcmp(T, U) == 0) {
        B--;
    }

    // Print the updated values of A and B.
    printf("%d %d\n", A, B);
}

int main() {
    char S[100], T[100], U[100];
    int A, B;

    // Read input values
    scanf("%s %s %d %d %s", S, T, &A, &B, U);

    // Call the 'solve' function with the assigned variables.
    solve(S, T, A, B, U);

    return 0;
}

// <END-OF-CODE>
