#include <stdio.h>
#include <string.h>

void solve(const char *S, const char *T, int *A, int *B, const char *U) {
    // Check if the first string S matches the string U
    if (strcmp(S, U) == 0) {
        (*A)--;  // Decrement A if S matches U
    }
    // Check if the second string T matches the string U
    if (strcmp(T, U) == 0) {
        (*B)--;  // Decrement B if T matches U
    }
    // Print the final values of A and B
    printf("%d %d\n", *A, *B);
}

int main() {
    char S[100], T[100], U[100]; // Assuming max length of strings is 99
    int A, B;

    // Read the first string S from input
    scanf("%s", S);
    // Read the second string T from input
    scanf("%s", T);
    // Read the integer A from input
    scanf("%d", &A);
    // Read the integer B from input
    scanf("%d", &B);
    // Read the string U from input
    scanf("%s", U);
    
    // Call the solve function with the read values
    solve(S, T, &A, &B, U);

    return 0;
}

// <END-OF-CODE>
