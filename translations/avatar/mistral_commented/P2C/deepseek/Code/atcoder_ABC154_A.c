#include <stdio.h>
#include <string.h>

// Function to solve the problem
void solve(char S[], char T[], int A, int B, char U[]) {
    // Check if S is equal to U
    if (strcmp(S, U) == 0) {
        A -= 1;
    }
    // Check if T is equal to U
    else if (strcmp(T, U) == 0) {
        B -= 1;
    }
    // Print the updated values of A and B
    printf("%d %d\n", A, B);
}

// Main function to read input and call solve
int main() {
    char S[100], T[100], U[100];
    int A, B;

    // Read input values
    scanf("%s %s %d %d %s", S, T, &A, &B, U);

    // Call the solve function
    solve(S, T, A, B, U);

    return 0;
}
