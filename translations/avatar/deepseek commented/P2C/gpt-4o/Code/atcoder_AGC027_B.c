#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Step 1: Reading Input
    int N, X;
    scanf("%d %d", &N, &X);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Step 2: Accumulating Sums
    long long *S = (long long *)malloc(N * sizeof(long long));
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    // Step 3: Initializing Answer
    long long ans = LLONG_MAX;

    // Step 4: Calculating Energy
    for (int k = 1; k <= N; k++) {
        long long E = k * X;
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }
        if (E < ans) {
            ans = E;
        }
    }

    // Step 5: Final Calculation
    printf("%lld\n", ans + N * X + 5 * S[N - 1]);

    // Free allocated memory
    free(A);
    free(S);

    return 0;
}

// <END-OF-CODE>
