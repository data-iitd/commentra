#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Set the value of modulo for modular arithmetic calculations
    int mod = 1000000007;

    // Read an integer n from the standard input
    int n;
    cin >> n;

    // Read n integers from the standard input and store them in a list c in descending order
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Calculate the value of b using the formula 2^(2*n-2) modulo mod
    int b = pow(2, 2 * n - 2, mod);

    // Calculate the value of a as 2*b modulo mod
    int a = 2 * b % mod;

    // Initialize the variable ans to zero
    int ans = 0;

    // Iterate through each index i from 0 to n-1 in the list c
    for (int i = 0; i < n; i++) {
        // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
        ans += c[i] * (a + i * b);
        // Update the value of ans by taking the modulo of the current sum with mod
        ans %= mod;
    }

    // Print the value of ans as the output
    cout << ans << endl;

    return 0;
}

