#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long *S = (long long *)malloc(N * sizeof(long long));
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    long long ans = LLONG_MAX;
    for (int k = 1; k <= N / 2; k++) {
        long long E = k * X;
        for (int j = N - 2 * k - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }
        ans = (E < ans) ? E : ans;
    }

    printf("%lld\n", ans + N * X + 5 * S[N - 1]);

    free(A);
    free(S);
    return 0;
}
// <END-OF-CODE>
