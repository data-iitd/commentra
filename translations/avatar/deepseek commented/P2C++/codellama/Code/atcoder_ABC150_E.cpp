
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int mod = 1000000007;
    // Define the modulo value as 10^9 + 7

    int n;
    // Read the integer input `n`
    cin >> n;

    int c[n];
    // Read the list of integers `c` and convert them to an array
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c, c + n, greater<int>());
    // Sort the array `c` in descending order

    int b = pow(2, 2 * n - 2, mod);
    // Calculate `b` using the power function with base 2, exponent (2 * n - 2), and modulo `mod`

    int a = 2 * b % mod;
    // Calculate `a` as twice `b` modulo `mod`

    int ans = 0;
    // Initialize `ans` to 0

    for (int i = 0; i < n; i++) {
        // Loop through each element in the range `n`
        ans += c[i] * (a + i * b);
        // Update `ans` with the sum of the product of `c[i]` and `(a + i * b)`
        ans %= mod;
        // Take modulo `mod` at each step to prevent overflow
    }

    cout << ans << endl;
    // Print the final result `ans`

    return 0;
}

