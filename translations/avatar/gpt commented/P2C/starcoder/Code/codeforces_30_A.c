#include <stdio.h>

int main() {
    int A, B, n, X;
    scanf("%d %d %d", &A, &B, &n);
    for (X = -1000; X <= 1000; X++) {
        if (A * (X ** n) == B) {
            printf("%d\n", X);
            break;
        }
    }
    if (X > 1000) {
        printf("No solution\n");
    }
    return 0;
}

