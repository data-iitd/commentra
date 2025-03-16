#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define the modulus value
const int mod = 1e9 + 7;

int main() {
    // Input the string S
    string S;
    getline(cin, S);
    int n = S.length();

    // Base case: if the length of the string is 1
    if (n == 1) {
        if (S == "5" || S == "?") {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    // Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
    vector<vector<long long>> dp(n, vector<long long>(13, 0));

    // Iterate through each index i from 0 to n-1
    for (int i = 0; i < n; i++) {
        // If i is the first index, process it differently
        if (i == 0) {
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i] != '?') {
                dp[i][S[i] - '0'] += 1;
            } else {
                // If the character at index i is '?', update all elements in the dp array accordingly
                for (int j = 0; j < 10; j++) {
                    dp[i][j] += 1;
                }
            }
        } else {
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i] != '?') {
                for (int k = 0; k < 13; k++) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + (S[i] - '0')) % 13] %= mod; // Ensure we take mod
                }
            } else {
                // If the character at index i is '?', update all elements in the dp array accordingly
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 13; k++) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                        dp[i][(k * 10 + j) % 13] %= mod; // Ensure we take mod
                    }
                }
            }
        }
    }

    // Print the final answer, which is dp[n-1][5]
    cout << dp[n - 1][5] << endl;

    return 0;
}

// <END-OF-CODE>
