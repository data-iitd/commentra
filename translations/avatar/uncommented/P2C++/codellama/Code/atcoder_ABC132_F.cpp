#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k, mod = 1000000007;
    cin >> n >> k;
    int coef[n];
    for (int i = 1; i <= int(sqrt(n)) + 1; i++)
    {
        coef[i] = (n / i) - (n / (i + 1));
    }
    coef[0] = 1;
    int nn = sizeof(coef) / sizeof(coef[0]);
    int dp[k + 1][nn];
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = nn - 1; j >= 0; j--)
        {
            int tmp = 0;
            for (int k = nn - 1; k >= 0; k--)
            {
                tmp += dp[i - 1][k];
                tmp %= mod;
                dp[i][j] = coef[j] * tmp;
                dp[i][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < nn; i++)
    {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

