
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;  // Set the modulus to 1e9 + 7

int main() {
    int n, k;
    cin >> n >> k;  // Read the values of n and k from input

    vector<int> coef(n + 1);  // Initialize the coefficient list
    for (int i = 1; i <= n; i++) {
        coef[i] = (n / i) - (n / (i + 1));  // Calculate the number of multiples of i
    }
    coef[n] = 1;  // Adjust for remaining numbers

    int nn = coef.size();  // Get the length of the coefficient list
    vector<vector<int>> dp(k + 1, vector<int>(nn));  // Initialize the dp table
    dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; i++) {
        int tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][(nn - 1) - j];  // Update the temporary sum
            tmp %= mod;
            dp[i][j] = coef[j] * tmp % mod;  // Update the dp table
        }
    }

    // Print the result: the sum of the last row of dp modulo mod
    int ans = 0;
    for (int i = 0; i < nn; i++) {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;  // Print the result

    return 0;
}
