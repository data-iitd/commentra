#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int M = 1000000;
    int fact[M][M];
    fact[0][0] = 1;
    for (int n = 1; n < M; n++)
    {
        for (int i = 0; i < n; i++)
            fact[i][n] = fact[i][n - 1] * (i + 1);
        for (int i = 0; i < n; i++)
            fact[n][n] *= fact[n - 1][i];
    }
    for (int n = 1; n < M; n++)
        fact[n] *= fact[n - 1][M - 1];
    int j[N];
    for (int i = 0; i < N; i++)
        j[i] = i;
    int inv[N];
    for (int i = 0; i < N; i++)
        inv[i] = pow(i + 1, MOD - 2, MOD);
    int temp[N];
    for (int i = 0; i < N; i++)
        temp[i] = inv[i] + inv[N - 1 - i] - 1;
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += A[i] * temp[i] % MOD;
    ans %= MOD;
    for (int i = 0; i < N; i++)
        ans *= fact[N][i];
    ans %= MOD;
    printf("%d\n", ans);
    return 0;
}

