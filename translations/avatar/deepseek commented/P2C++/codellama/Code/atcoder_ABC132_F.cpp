#include <iostream>
#include <cmath>
using namespace std;

const int mod = 1000000007;  // Set the modulus to 10^9 + 7
int n, k;  // Declare the variables n and k

int main() {
    cin >> n >> k;  // Read the values of n and k from input

    // Calculate the coefficients for the number of multiples of each divisor up to n
    int coef[n];
    for (int i = 1; i <= int(sqrt(n)) + 1; i++) {
        coef[i - 1] = (n / i) - (n / (i + 1));  // Calculate the number of multiples of i
    }
    for (int i = int(sqrt(n)) + 1; i < n; i++) {
        coef[i] = 1;  // Adjust for remaining numbers
    }

    int nn = n;  // Get the length of the coefficient list
    int dp[k + 1][nn];  // Initialize the dp table
    dp[0][0] = 1;  // Base case: one way to achieve sum 0 with 0 elements

    // Dynamic programming to calculate the number of ways to achieve sums with up to k elements
    for (int i = 1; i <= k; i++) {
        int tmp = 0;  // Temporary variable to accumulate the sum of previous row's values
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][(nn - 1) - j];  // Update the temporary sum
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;  // Update the dp table
            dp[i][j] %= mod;
        }
    }

    // Print the result: the sum of the last row of dp modulo mod
    int ans = 0;
    for (int i = 0; i < nn; i++) {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}

