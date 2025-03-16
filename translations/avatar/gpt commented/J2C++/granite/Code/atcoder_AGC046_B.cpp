
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a constant for the modulo operation
const long long MOD = 998244353LL;

int main() {
    // Read input values A, B, C, D from the console
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Create a 2D vector for dynamic programming
    vector<vector<long long>> dp(C + 1, vector<long long>(D + 1, 0));

    // Initialize the starting point in the dp vector
    dp[A][B] = 1;

    // Iterate over the range from A to C and B to D
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            // Skip the initial point
            if (c == A && d == B) {
                continue;
            }

            // Variable to store the current answer
            long long ans = 0;

            // If moving down (increasing c)
            if (c > A) {
                long long part = dp[c - 1][d];
                ans = (part * d); // Calculate contribution from the previous row
            }

            // If moving right (increasing d)
            if (d > B) {
                long long part = dp[c][d - 1];
                ans = (ans + (part * c)); // Calculate contribution from the previous column
            }

            // If moving diagonally (increasing both c and d)
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Adjust for double counting
            }

            // Store the result in the dp vector with modulo adjustment
            dp[c][d] = ((ans % MOD) + MOD) % MOD;
        }
    }

    // Output the final result for dp[C][D]
    cout << dp[C][D] << endl;

    return 0;
}

