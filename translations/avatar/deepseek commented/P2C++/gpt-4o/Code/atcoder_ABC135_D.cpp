#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;  // Define modulo constant

int main() {
    string S;
    cin >> S;  // Read input string
    int n = S.length();  // Get length of the string

    if (n == 1) {  // Check if the string length is 1
        if (S == "5" || S == "?") {  // Check if the string is '5' or '?'
            cout << 1 << endl;  // Print 1 if true
        } else {
            cout << 0 << endl;  // Print 0 otherwise
        }
        return 0;  // Exit the program
    }

    vector<vector<long long>> dp(n, vector<long long>(13, 0));  // Initialize dp array

    for (int i = 0; i < n; i++) {  // Iterate over the length of the string
        if (i == 0) {  // Base case for the first character
            if (S[i] != '?') {  // Check if the character is not '?'
                dp[i][S[i] - '0'] += 1;  // Update dp value directly
            } else {
                for (int j = 0; j < 10; j++) {  // Iterate over all possible digits
                    dp[i][j] += 1;  // Increment dp value
                }
            }
        } else {  // General case for subsequent characters
            if (S[i] != '?') {  // Check if the character is not '?'
                for (int k = 0; k < 13; k++) {  // Iterate over all possible remainders
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];  // Update dp value
                }
            } else {
                for (int j = 0; j < 10; j++) {  // Iterate over all possible digits
                    for (int k = 0; k < 13; k++) {  // Iterate over all possible remainders
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];  // Update dp value
                    }
                }
            }
            for (int k = 0; k < 13; k++) {  // Apply modulo to prevent overflow
                dp[i][k] %= mod;
            }
        }
    }
    cout << dp[n - 1][5] << endl;  // Print the result
    return 0;
}

// <END-OF-CODE>
