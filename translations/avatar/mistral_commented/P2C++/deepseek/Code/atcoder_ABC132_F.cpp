#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    const long long mod = 1000000007;
    int n, k;
    cin >> n >> k;

    vector<int> coef;

    for (int i = 1; i <= sqrt(n); ++i) {
        coef.push_back(n / i - n / (i + 1));
    }

    int remaining = n - coef.size();
    for (int i = 0; i < remaining; ++i) {
        coef.push_back(1);
    }

    reverse(coef.begin(), coef.end());

    int nn = coef.size();
    vector<vector<long long>> dp(k + 1, vector<long long>(nn, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= k; ++i) {
        long long tmp = 0;
        for (int j = nn - 1; j >= 0; --j) {
            tmp = (tmp + dp[i - 1][j]) % mod;
            tmp = (tmp + coef[j]) % mod;
            dp[i][j] = (coef[j] * tmp) % mod;
        }
    }

    long long answer = 0;
    for (int j = 0; j < nn; ++j) {
        answer = (answer + dp[k][j]) % mod;
    }

    cout << answer << endl;

    return 0;
}

