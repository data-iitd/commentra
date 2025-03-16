
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coef;
    for (int i = 1; i <= n; i++) {
        coef.push_back((n / i) - (n / (i + 1)));
    }

    int nn = coef.size();
    vector<vector<int>> dp(k + 1, vector<int>(nn, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][nn - 1 - j];
            tmp %= mod;
            dp[i][j] = coef[j] * tmp % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < nn; i++) {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}

