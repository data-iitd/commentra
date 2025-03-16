
#include <iostream>
#include <string>

using namespace std;

// Define the modulus value for calculations to prevent overflow
const int mod = 1e9 + 7;

int main() {
    string l;
    cin >> l;

    int n = l.length();

    // Initialize a 2D vector (dp) to store the number of ways to form valid sequences
    // dp[i][0] will store the count of sequences ending with '0'
    // dp[i][1] will store the count of sequences ending with '1'
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Base case: there's one way to have an empty sequence
    dp[0][0] = 1;

    // Iterate through each character in the input string
    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            // If the current character is '0', update the counts for sequences ending with '0'
            dp[i + 1][0] = (dp[i + 1][0] + dp[i][0]) % mod;
            // Update counts for sequences ending with '1' (can be formed by adding '0' to previous '1' sequences)
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][1] * 3) % mod;
        } else {
            // If the current character is '1', update the counts for sequences ending with '0'
            dp[i + 1][0] = (dp[i + 1][0] + dp[i][0] * 2) % mod;
            // Update counts for sequences ending with '1'
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0] + dp[i][1] * 3) % mod;
        }
    }

    // Calculate the total number of valid sequences by summing both counts for the last character
    int result = (dp[n][0] + dp[n][1]) % mod;

    cout << result << endl;

    return 0;
}
