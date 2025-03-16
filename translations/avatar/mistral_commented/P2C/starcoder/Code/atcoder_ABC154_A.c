#include <stdio.h>
#include <string.h>

int main() {
    char S[100000], T[100000], U[100000];
    int A, B;
    scanf("%s %s %d %d %s", S, T, &A, &B, U);
    if (strcmp(S, U) == 0) A--;
    if (strcmp(T, U) == 0) B--;
    printf("%d %d\n", A, B);
    return 0;
}

