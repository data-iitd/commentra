#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coef;

    for (int i = 1; i <= sqrt(n); ++i) {
        coef.push_back((n / i) - (n / (i + 1)));
    }

    int nn = coef.size();
    vector<vector<int>> dp(k + 1, vector<int>(nn, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= k; ++i) {
        int tmp = 0;
        for (int j = nn - 1; j >= 0; --j) {
            tmp = (tmp + dp[i - 1][(nn - 1) - j]) % mod;
            dp[i][j] = (coef[j] * tmp) % mod;
        }
    }

    int result = 0;
    for (int j = 0; j < nn; ++j) {
        result = (result + dp[k][j]) % mod;
    }

    cout << result << endl;

    return 0;
}
