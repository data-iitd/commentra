#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int M = 1000000;
    int fact[M][M];
    fact[0][0] = 1;
    for (int n = 1; n < M; n++) {
        fact[n][0] = fact[n - 1][0] * n % MOD;
        for (int m = 1; m < n; m++) {
            fact[n][m] = fact[n][m - 1] * n % MOD;
        }
        fact[n][n] = fact[n][n - 1] * n % MOD;
    }
    int temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = (fact[i][i] + fact[N - 1 - i][N - 1 - i] - 1) % MOD;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * temp[i] % MOD;
        ans %= MOD;
    }
    ans *= fact[N][N];
    ans %= MOD;
    printf("%d\n", ans);
    return 0;
}

