#include <bits/stdc++.h>
using namespace std;

// Define the modulus value for calculations to prevent overflow
const int mod = 1000000007;

int main() {
    // Read input values for n and k
    int n, k;
    cin >> n >> k;

    // Initialize a list to store coefficients
    vector<int> coef;

    // Calculate coefficients based on the divisors of n
    for (int i = 1; i <= sqrt(n); i++) {
        // Append the count of divisors in the range
        coef.push_back((n / i) - (n / (i + 1)));
    }

    // Fill the remaining coefficients with 1s to ensure the length matches n
    while (coef.size() < n) {
        coef.push_back(1);
    }

    // Reverse the coefficients list for further processing
    reverse(coef.begin(), coef.end());

    // Get the length of the coefficients list
    int nn = coef.size();

    // Initialize a 2D list for dynamic programming
    // dp[i][j] will store the result for i selections and j coefficients
    vector<vector<int>> dp(k + 1, vector<int>(nn, 0));

    // Base case: there's one way to select 0 items (select nothing)
    dp[0][0] = 1;

    // Fill the dp table for k selections
    for (int i = 1; i <= k; i++) {
        int tmp = 0;  // Temporary variable to accumulate values
        // Iterate through the coefficients in reverse order
        for (int j = nn - 1; j >= 0; j--) {
            // Accumulate the number of ways to select items
            tmp += dp[i - 1][j];
            tmp %= mod;  // Ensure the value stays within modulus
            // Calculate the number of ways to select i items using the j-th coefficient
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;  // Again, ensure the value stays within modulus
    }

    // Output the total number of ways to select k items, taking modulus
    cout << dp[k][0];
}

