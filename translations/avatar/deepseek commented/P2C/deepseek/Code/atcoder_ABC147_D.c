#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long result = 0;

    for (int b = 0; b < 60; b++) {
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if ((A[i] >> b) & 1) {
                bs++;
            }
        }

        result = (result + (long long)bs * (N - bs) * (1LL << b)) % MOD;
    }

    printf("%lld\n", result);

    free(A);
    return 0;
}
