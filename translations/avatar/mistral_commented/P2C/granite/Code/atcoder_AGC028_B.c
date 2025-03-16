
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 100000007

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int fact[1000][1000];
    for (int i = 0; i < 1000; i++) {
        fact[i][0] = 1;
    }
    for (int i = 1; i < 1000; i++) {
        for (int j = 1; j < 1000; j++) {
            fact[i][j] = fact[i - 1][j] * fact[i][j - 1] % MOD;
        }
    }
    int inv[N];
    for (int i = 0; i < N; i++) {
        inv[i] = pow(i + 1, MOD - 2) % MOD;
    }
    int temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = inv[i] + inv[N - 1 - i] - 1;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (long long)A[i] * temp[i] % MOD;
    }
    ans %= MOD;
    ans *= fact[N][N];
    ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}
