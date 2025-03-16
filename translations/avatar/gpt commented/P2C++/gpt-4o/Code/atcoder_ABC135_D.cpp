#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the modulo constant
const int mod = 1e9 + 7;

int main() {
    // Read the string input S
    string S;
    cin >> S;
    int n = S.length();

    // Handle the case where the input string length is 1
    if (n == 1) {
        if (S == "5" || S == "?") {
            cout << 1 << endl;  // Output 1 if the single character is '5' or '?'
        } else {
            cout << 0 << endl;  // Output 0 for any other single character
        }
        return 0;
    }

    // Initialize a 2D vector for dynamic programming
    vector<vector<int>> dp(n, vector<int>(13, 0));

    // Fill the dp table based on the characters in S
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // Handle the first character
            if (S[i] != '?') {
                dp[i][S[i] - '0'] += 1;  // Increment the count for the specific digit
            } else {
                // If the character is '?', increment counts for all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        } else {
            // Process subsequent characters
            if (S[i] != '?') {
                // If the character is a specific digit
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                }
            } else {
                // If the character is '?', consider all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
        }

        // Apply modulo to keep the values manageable
        for (int k = 0; k < 13; k++) {
            dp[i][k] %= mod;
        }
    }

    // Output the count of valid numbers that are divisible by 13 and end with digit 5
    cout << dp[n - 1][5] << endl;

    return 0;
}

// <END-OF-CODE>
