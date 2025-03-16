#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long result = 0;
    for (int b = 0; b < 60; b++) {
        long long bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }
        result = (result + bs * (N - bs) * (1LL << b)) % MOD;
    }

    printf("%lld\n", result);
    free(A);
    return 0;
}

// <END-OF-CODE>
