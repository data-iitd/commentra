#include <stdio.h>
#include <math.h>

int main() {
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);

    // Step 1: Handling Special Case A == 0
    if (A == 0) {
        if (B == 0) {
            printf("1\n");
        } else {
            printf("No solution\n");
        }
        return 0;
    }

    // Step 2: Checking Divisibility
    if (B % A != 0) {
        printf("No solution\n");
        return 0;
    }

    // Step 3: Normalizing B
    B /= A;
    int neg = B < 0;
    if (neg && n % 2 == 0) {
        printf("No solution\n");
        return 0;
    }
    if (neg) {
        B = -B;
    }

    // Step 4: Iterating to Find Solution
    for (int x = 0; x <= B; x++) {
        if (pow(x, n) == B) {
            printf(neg ? "-%d\n" : "%d\n", neg ? -x : x);
            return 0;
        }
    }

    // Step 5: No Solution Found
    printf("No solution\n");
    return 0;
}
