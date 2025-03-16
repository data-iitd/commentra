
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = A[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, A[i]);
    }

    printf("%d\n", result);

    free(A);
    return 0;
}

