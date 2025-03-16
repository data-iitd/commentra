
#include <bits/stdc++.h>

using namespace std;

// Set the modulus value
const int mod = 1000000007;

int main() {
    // Read input values for n and k
    int n, k;
    cin >> n >> k;

    // Initialize a list 'coef' to store coefficients
    vector<int> coef;

    // Calculate coefficients for n up to its square root
    for (int i = 1; i <= sqrt(n); i++) {
        // Calculate the difference between the quotient and the next quotient
        coef.push_back(n / i - n / (i + 1));
    }

    // Add remaining coefficients to the list
    coef.resize(n - coef.size(), 1);

    // Reverse the list 'coef'
    reverse(coef.begin(), coef.end());

    // Initialize a 2D list 'dp' to store intermediate results
    vector<vector<int>> dp(k + 1, vector<int>(coef.size()));

    // Initialize the first row of dp with 1 at index 0
    dp[0][0] = 1;

    // Calculate dp[i][j] for i from 1 to k and j from coef.size()-1 to 0
    for (int i = 1; i <= k; i++) {
        int tmp = 0;
        // Iterate through the reverse list 'coef' from j = coef.size()-1 to j = 0
        for (int j = coef.size() - 1; j >= 0; j--) {
            // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
            tmp += dp[i - 1][j];
            tmp = (tmp + coef[j]) % mod;
            // Update dp[i][j] with the product of coef[j] and tmp
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }

    // Calculate the final answer by summing up dp[k]
    cout << accumulate(dp[k].begin(), dp[k].end(), 0) % mod << endl;

    return 0;
}

