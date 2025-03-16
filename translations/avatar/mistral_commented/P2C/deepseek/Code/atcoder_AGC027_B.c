#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, *A, *S;
    int i, j, k;
    long long E, sum = 0, ans = LLONG_MAX;

    // Read input
    scanf("%d %d", &N, &X);
    A = (int*)malloc(N * sizeof(int));
    S = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Create the list S by applying the accumulate function to the list A
    S[0] = A[0];
    for (i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    // Iterate through each element s in the list S
    for (k = 1; k <= N; k++) {
        E = k * X + 2 * (S[N - 1] - S[k - 1] - (N - 2 * k) * S[k - 1]);
        if (E < ans) {
            ans = E;
        }
    }

    // Print the result
    printf("%lld\n", ans + N * X + 5 * S[N - 1]);

    // Free allocated memory
    free(A);
    free(S);

    return 0;
}
