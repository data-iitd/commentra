#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
void solve(long long N, long long *T, long long M, long long *P, long long *X) {
=======
void solve(long long N, long long* T, long long M, long long* P, long long* X) {
>>>>>>> 98c87cb78a (data updated)
    for (long long i = 0; i < M; i++) {
        long long ans = 0;
        for (long long j = 0; j < N; j++) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%lld\n", ans);
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
<<<<<<< HEAD
    long long *T = (long long *)malloc(N * sizeof(long long));
=======
    long long* T = (long long*)malloc(N * sizeof(long long));
>>>>>>> 98c87cb78a (data updated)
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &T[i]);
    }
    
    long long M;
    scanf("%lld", &M);
<<<<<<< HEAD
    long long *P = (long long *)malloc(M * sizeof(long long));
    long long *X = (long long *)malloc(M * sizeof(long long));
=======
    long long* P = (long long*)malloc(M * sizeof(long long));
    long long* X = (long long*)malloc(M * sizeof(long long));
>>>>>>> 98c87cb78a (data updated)
    for (long long i = 0; i < M; i++) {
        scanf("%lld %lld", &P[i], &X[i]);
    }
    
    solve(N, T, M, P, X);
    
    free(T);
    free(P);
    free(X);
    
    return 0;
}

// <END-OF-CODE>
