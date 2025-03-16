#include <stdio.h>
#include <math.h>

void solve(void) {
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);

    if (A == 0) {
        if (B == 0) {
            printf("1\n");
        } else {
            printf("No solution\n");
            return;
        }
        return;
    }

    if (B % A != 0) {
        printf("No solution\n");
        return;
    }

    B /= A;
    int neg = B < 0;

    if (neg && n % 2 == 0) {
        printf("No solution\n");
        return;
    }

    if (neg) B = -B;

    for (int x = 0; x <= B; x++) {
        if (pow(x, n) == B) {
            printf("%d\n", neg ? -x : x);
            return;
        }
    }

    printf("No solution\n");
}

int main(void) {
    solve();
    return 0;
}

