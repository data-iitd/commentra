#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int mod = 1000000007;

int main() {
    string l;
    cin >> l;
    int n = l.length();

    // Initialize 2D dynamic programming table
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

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
