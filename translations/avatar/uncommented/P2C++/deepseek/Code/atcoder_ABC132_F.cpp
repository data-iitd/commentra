#include <iostream>
#include <vector>
#include <cmath>

const long long mod = 1000000007;

int main() {
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> coef;
    for (long long i = 1; i <= std::sqrt(n); ++i) {
        coef.push_back((n / i) - (n / (i + 1)));
    }
    coef.push_back(n - std::accumulate(coef.begin(), coef.end(), 0LL));
    std::reverse(coef.begin(), coef.end());

    long long nn = coef.size();
    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(nn, 0));
    dp[0][0] = 1;

    for (long long i = 1; i <= k; ++i) {
        long long tmp = 0;
        for (long long j = nn - 1; j >= 0; --j) {
            tmp += dp[i - 1][nn - 1 - j];
            tmp %= mod;
            dp[i][j] = coef[j] * tmp % mod;
        }
    }

    long long result = 0;
    for (long long j = 0; j < nn; ++j) {
        result += dp[k][j];
        result %= mod;
    }

    std::cout << result << std::endl;
    return 0;
}

