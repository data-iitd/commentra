#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int M = 1000000007; // Defining a constant for modulo operation
    string s;
    getline(cin, s); // Reading the input string
    int n = s.length(); // Getting the length of the input string
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // Initializing the dynamic programming table
    dp[0][0] = 1; // Setting the base case for dp[0][0]

    // Iterating through each character of the input string
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0]; // Copying the previous state for '0'
            dp[i + 1][1] = dp[i][1]; // Copying the previous state for '0'
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M; // Updating dp[i+1][1] for '1'
        }

        // Additional updates for '0' and '1'
        if (s[i] == '0') {
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % M) % M; // Updating dp[i+1][1] for '0'
        } else {
            dp[i + 1][0] = (dp[i + 1][0] + (dp[i][0] * 2) % M) % M; // Updating dp[i+1][0] for '1'
            dp[i + 1][1] = (dp[i + 1][1] + (dp[i][1] * 2) % M) % M; // Updating dp[i+1][1] for '1'
        }
    }

    // Printing the result as the sum of dp[n][0] and dp[n][1] modulo M
    cout << (dp[n][0] + dp[n][1]) % M << endl;

    return 0;
}

// <END-OF-CODE>
