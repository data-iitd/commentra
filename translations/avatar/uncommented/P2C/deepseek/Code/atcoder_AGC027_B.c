#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, *A, i, j, k;
    long long ans = LLONG_MAX, E;

    // Read input
    scanf("%d %d", &N, &X);
    A = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate prefix sums
    for (i = 1; i < N; i++) {
        A[i] += A[i - 1];
    }

    // Calculate the answer
    for (k = 1; k <= N / 2; k++) {
        E = k * X + 2 * (A[N - 1] - A[N - 2 * k - 1]);
        for (j = N - 2 * k - 1; j >= 0; j -= k) {
            E += S[j];
        }
        ans = (E < ans) ? E : ans;
    }

    // Print the result
    printf("%lld\n", ans + N * X + 5 * A[N - 1]);

    // Free allocated memory
    free(A);
    return 0;
}
