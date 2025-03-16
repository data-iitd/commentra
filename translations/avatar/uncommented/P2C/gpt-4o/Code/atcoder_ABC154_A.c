#include <stdio.h>
#include <string.h>

void solve(char *S, char *T, int A, int B, char *U) {
    if (strcmp(S, U) == 0) {
        A -= 1;
    }
    if (strcmp(T, U) == 0) {
        B -= 1;
    }
    printf("%d %d\n", A, B);
}

int main() {
    char S[100], T[100], U[100];
    int A, B;

    // Read input
    scanf("%s %s %d %d %s", S, T, &A, &B, U);

    solve(S, T, A, B, U);

    return 0;
}

// <END-OF-CODE>
