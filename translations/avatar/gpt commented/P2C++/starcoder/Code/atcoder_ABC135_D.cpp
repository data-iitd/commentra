#include <bits/stdc++.h>
using namespace std;

// Set the recursion limit to a higher value to handle deep recursions
const int N = 100000;
const int mod = 1000000007;
int dp[N][13];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    int n = S.length();

    // Handle the case where the input string length is 1
    if (n == 1) {
        if (S == "5" || S == "?") {
            cout << 1 << "\n";  // Output 1 if the single character is '5' or '?'
        } else {
            cout << 0 << "\n";  // Output 0 for any other single character
        }
        return 0;
    }

    // Initialize a 2D list for dynamic programming
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 13; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp table based on the characters in S
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // Handle the first character
            if (S[i]!= '?') {
                dp[i][(int)(S[i] - '0')] += 1;  // Increment the count for the specific digit
            } else {
                // If the character is '?', increment counts for all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        } else {
            // Process subsequent characters
            if (S[i]!= '?') {
                // If the character is a specific digit
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (int)(S[i] - '0')) % 13] += dp[i - 1][k];
                }
            } else {
                // If the character is '?', consider all digits (0-9)
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }

            // Apply modulo to keep the values manageable
            for (int k = 0; k < 13; k++) {
                dp[i][k] %= mod;
            }
        }
    }

    // Output the count of valid numbers that are divisible by 13 and end with digit 5
    cout << dp[n - 1][5] << "\n";

    return 0;
}

