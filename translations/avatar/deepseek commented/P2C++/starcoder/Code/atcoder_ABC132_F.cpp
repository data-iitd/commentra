#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int mod = 1000000007;  // Set the modulus to 10^9 + 7
    vector<int> coef(n, 0);  // Initialize the coefficient list
    for (int i = 1; i <= sqrt(n); i++) {
        coef[i] = (n / i) - (n / (i + 1));  // Calculate the number of multiples of i
    }
    for (int i = sqrt(n); i < n; i++) {
        coef[i] = 1;  // Adjust for remaining numbers
    }
    reverse(coef.begin(), coef.end());  // Reverse the coefficients for dynamic programming

    int nn = coef.size();  // Get the length of the coefficient list
    vector<vector<int>> dp(k + 1, vector<int>(nn, 0));  // Initialize the dp table
    dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; i++) {
        int tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][j];  // Update the temporary sum
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;  // Update the dp table
            dp[i][j] %= mod;
        }
    }

    // Print the result: the sum of the last row of dp modulo mod
    cout << dp[k][0] << "\n";

    return 0;
}

