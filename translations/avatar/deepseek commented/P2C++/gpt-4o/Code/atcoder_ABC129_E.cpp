#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;  // Set the modulus to a large prime number

int main() {
    string l;  // Read the input string
    cin >> l;  
    int n = l.length();  // Calculate the length of the input string

    // Initialize the dynamic programming table
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[0][0] = 1;  // Base case: one empty sequence

    // Iterate over each character in the input string
    for (int i = 0; i < n; ++i) {
        char c = l[i];
        if (c == '0') {
            dp[i + 1][0] += dp[i][0];  // Add sequences ending with zero
            dp[i + 1][1] += dp[i][1] * 3;  // Triple sequences ending with one
        } else {
            dp[i + 1][0] += dp[i][0] * 2;  // Double sequences ending with zero
            dp[i + 1][1] += dp[i][0];  // Add sequences ending with zero
            dp[i + 1][1] += dp[i][1] * 3;  // Triple sequences ending with one
        }

        // Take modulo to prevent overflow
        dp[i + 1][0] %= mod;
        dp[i + 1][1] %= mod;
    }

    // Calculate and print the final result
    long long result = (dp[n][0] + dp[n][1]) % mod;
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
