#include <iostream>
#include <vector>

using namespace std;

// Modulus constant for fast modular arithmetic
const int mod = 1e9 + 7;

int main() {
    // Read input string
    string l;
    cin >> l;
    int n = l.length();

    // Initialize 2D dynamic programming table
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    // Base case: empty string has 1 solution
    dp[0][0] = 1;

    // Iterate through each character in the input string
    for (int i = 0; i < n; ++i) {
        char c = l[i];
        // Update dp[i+1][0] based on current character '0' or '1'
        if (c == '0') {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][1] += dp[i][1] * 3;
        } else {
            dp[i + 1][0] += dp[i][0] * 2;
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][1] += dp[i][1] * 3;
        }

        // Perform modular arithmetic to keep the values within the modulus
        dp[i + 1][0] %= mod;
        dp[i + 1][1] %= mod;
    }

    // Calculate the final answer
    cout << (dp[n][0] + dp[n][1]) % mod << endl;

    return 0;
}

// <END-OF-CODE>
