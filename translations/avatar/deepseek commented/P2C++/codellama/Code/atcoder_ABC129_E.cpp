#include <iostream>
#include <string>

using namespace std;

int main() {
    int mod = 1000000007;  // Set the modulus to a large prime number
    string l;  // Read the input string
    cin >> l;
    int n = l.length();  // Calculate the length of the input string

    // Initialize the dynamic programming table
    int dp[n + 1][2];
    dp[0][0] = 1;  // Base case: one empty sequence

    // Iterate over each character in the input string
    for (int i = 0; i < n; i++) {
        if (l[i] == '0') {
            dp[i + 1][0] = (dp[i][0] + dp[i][1] * 3) % mod;  // Triple sequences ending with one
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;  // Add sequences ending with zero
        } else {
            dp[i + 1][0] = (dp[i][0] * 2 + dp[i][1] * 3) % mod;  // Double sequences ending with zero
            dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % mod;  // Triple sequences ending with one
        }
    }

    // Calculate and print the final result
    int result = (dp[n][0] + dp[n][1]) % mod;
    cout << result << endl;

    return 0;
}

