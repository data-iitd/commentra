#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define mod 1000000007
int main()
{
    int n, k, i, j, tmp, nn, coef[100000], dp[100000][100000];
    scanf("%d %d", &n, &k);
    nn = (int)sqrt(n);
    for (i = 1; i <= nn; i++)
    {
        coef[i] = (n / i) - (n / (i + 1));
    }
    coef[nn + 1] = 1;
    for (i = nn + 2; i <= n; i++)
    {
        coef[i] = 0;
    }
    dp[0][0] = 1;
    for (i = 1; i <= k; i++)
    {
        tmp = 0;
        for (j = nn - 1; j >= 0; j--)
        {
            tmp += dp[i - 1][(nn - 1) - j];
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }
    tmp = 0;
    for (i = 0; i < nn; i++)
    {
        tmp += dp[k][i];
        tmp %= mod;
    }
    printf("%d", tmp);
    return 0;
}
