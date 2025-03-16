#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;  // Set the modulus to 10^9 + 7

int main() {
    long long n, k;
    cin >> n >> k;  // Read the values of n and k from input

    // Calculate the coefficients for the number of multiples of each divisor up to n
    vector<long long> coef;
    for (long long i = 1; i * i <= n; ++i) {
        coef.push_back(n / i - n / (i + 1));  // Calculate the number of multiples of i
    }
    coef.resize(coef.size() + (n - (n / (coef.size() + 1))));  // Adjust for remaining numbers
    reverse(coef.begin(), coef.end());  // Reverse the coefficients for dynamic programming

    int nn = coef.size();  // Get the length of the coefficient list
    vector<vector<long long>> dp(k + 1, vector<long long>(nn, 0));  // Initialize the dp table
    dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; ++i) {
        long long tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
        for (int j = nn - 1; j >= 0; --j) {
            tmp += dp[i - 1][nn - 1 - j];  // Update the temporary sum
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;  // Update the dp table
            dp[i][j] %= mod;
        }
    }

    // Print the result: the sum of the last row of dp modulo mod
    long long result = 0;
    for (int j = 0; j < nn; ++j) {
        result += dp[k][j];
        result %= mod;
    }
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
