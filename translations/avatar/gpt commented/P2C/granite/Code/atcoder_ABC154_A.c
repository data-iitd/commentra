
#include <stdio.h>

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
    return;
}

int main() {
    // Define a function to read a string from standard input
    char S[100];
    fgets(S, sizeof(S), stdin);
    // Define a function to read an integer from standard input
    int A, B;
    scanf("%d %d", &A, &B);
    // Define a function to read a string from standard input
    char U[100];
    fgets(U, sizeof(U), stdin);
    
    // Call the solve function with the read values
    solve(S, T, A, B, U);
    
    return 0;
}

