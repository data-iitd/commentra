#include <stdio.h>
#include <stdlib.h>

void solve(long long N, long long *T, long long M, long long *P, long long *X, long long *results) {
    for (long long i = 0; i < M; i++) {
        long long ans = 0;
        for (long long j = 0; j < N; j++) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        results[i] = ans;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long *T = (long long *)malloc(N * sizeof(long long));
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &T[i]);
    }
    long long M;
    scanf("%lld", &M);
    long long *P = (long long *)malloc(M * sizeof(longlong));
    long long *X = (long long *)malloc(M * sizeof(long long));
    for (long long i = 0; i < M; i++) {
        scanf("%lld %lld", &P[i], &X[i]);
    }
    long long *results = (long long *)malloc(M * sizeof(long long));
    solve(N, T, M, P, X, results);
    for (long long i = 0; i < M; i++) {
        printf("%lld\n", results[i]);
    }
    free(T);
    free(P);
    free(X);
    free(results);
    return 0;
}
