#include <stdio.h>
#include <math.h>

int task4(int A, int B, int n) {
    for (int X = -1000; X <= 1000; X++) {
        if (A * pow(X, n) == B) {
            return X;
        }
    }
    return -1; // Return -1 to indicate no solution
}

int main() {
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);
    int result = task4(A, B, n);
    if (result == -1) {
        printf("No solution\n");
    } else {
        printf("%d\n", result);
    }
    return 0;
}

