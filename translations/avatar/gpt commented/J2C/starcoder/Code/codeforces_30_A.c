#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);
    if (A == 0) {
        if (B == 0) {
            printf("1\n");
        } else {
            printf("No solution\n");
        }
        return 0;
    }
    if (B % A!= 0) {
        printf("No solution\n");
        return 0;
    }
    B /= A;
    if (B < 0 && n % 2 == 0) {
        printf("No solution\n");
        return 0;
    }
    if (B < 0) {
        B = -B;
    }
    for (int x = 0; x <= B; x++) {
        if (pow(x, n) == B) {
            printf("%d\n", B < 0? -x : x);
            return 0;
        }
    }
    printf("No solution\n");
    return 0;
}

