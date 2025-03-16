#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, X, *A, *S;
    int i, j, k, sum, E, ans;

    // Step 1: Reading Input
    scanf("%d %d", &N, &X);
    A = (int*)malloc(N * sizeof(int));
    S = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Step 2: Accumulating Sums
    S[0] = A[0];
    for (i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    // Step 3: Initializing Answer
    ans = INT_MAX;

    // Step 4: Calculating Energy
    for (k = 1; k <= N; k++) {
        sum = 0;
        for (j = N - 2 * k - 1; j >= 0; j -= k) {
            sum += S[j];
        }
        E = k * X + 2 * sum;
        if (E < ans) {
            ans = E;
        }
    }

    // Step 5: Final Calculation
    printf("%d\n", ans + N * X + 5 * S[N - 1]);

    // Free allocated memory
    free(A);
    free(S);

    return 0;
}
