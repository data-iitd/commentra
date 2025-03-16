#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    long long n, k;
    cin >> n >> k;
    
    vector<long long> coef;
    for (long long i = 1; i * i <= n; ++i) {
        coef.push_back(n / i - n / (i + 1));
    }
    coef.insert(coef.end(), n - accumulate(coef.begin(), coef.end(), 0LL), 1);
    reverse(coef.begin(), coef.end());
    
    int nn = coef.size();
    vector<vector<long long>> dp(k + 1, vector<long long>(nn, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= k; ++i) {
        long long tmp = 0;
        for (int j = nn - 1; j >= 0; --j) {
            tmp = (tmp + dp[i - 1][nn - 1 - j]) % mod;
            dp[i][j] = (coef[j] * tmp) % mod;
        }
    }
    
    long long result = 0;
    for (int j = 0; j < nn; ++j) {
        result = (result + dp[k][j]) % mod;
    }
    
    cout << result << endl;
    return 0;
}

// <END-OF-CODE>
