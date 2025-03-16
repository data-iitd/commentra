

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coef;
    for (int i = 1; i * i <= n; i++) {
        coef.push_back(n / i - n / (i + 1));
    }
    for (int i = 1; i <= n - coef.size(); i++) {
        coef.push_back(1);
    }
    reverse(coef.begin(), coef.end());

    vector<vector<int>> dp(k + 1, vector<int>(coef.size()));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        for (int j = coef.size() - 1; j >= 0; j--) {
            tmp += dp[i - 1][j];
            tmp %= MOD;
            dp[i][j] = coef[j] * 1ll * tmp % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < coef.size(); i++) {
        ans += dp[k][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}

