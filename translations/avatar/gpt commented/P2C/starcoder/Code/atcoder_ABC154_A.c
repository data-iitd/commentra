#include <stdio.h>
#include <string.h>

int main() {
    char S[1000001];
    char T[1000001];
    char U[1000001];
    scanf("%s", S);
    scanf("%s", T);
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%s", U);
    if (strcmp(S, U) == 0) {
        A--;
    }
    if (strcmp(T, U) == 0) {
        B--;
    }
    printf("%d %d", A, B);
    return 0;
}

