#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate (x^n) % mod using recursion
long long power(long long x, long long n, int mod) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }

    // Recursively calculate power
    long long val = power(x, n / 2, mod);

    // Square the result and take modulus
    val = (val * val) % mod;

    // If n is odd, multiply by x and take modulus
    if (n % 2 == 1) {
        val = (val * x) % mod;
    }

    // Return the final result
    return val;
}

int main() {
    // Create a vector to read input
    int n;
    cin >> n;

    // Initialize a vector 'c' of size 'n'
    vector<int> c(n);

    // Populate the vector 'c' with integers from the input
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Define a modulus value for calculations
    int mod = 1000000007;

    // If there is only one element, calculate and print the result directly
    if (n == 1) {
        cout << (c[0] * 2LL % mod) << endl;
        return 0;
    }

    // Sort the vector 'c'
    sort(c.begin(), c.end());

    // Calculate powers of 2 for later use
    long long b = power(2, n, mod);
    long long a = power(2, n - 2, mod);

    // Initialize the answer variable
    long long ans = 0;

    // Calculate the final answer using a loop
    for (int i = 2; i <= n + 1; i++) {
        // Calculate the value for the current iteration
        long long val = (a * i % mod) * c[n + 1 - i] % mod;

        // Accumulate the result
        ans = (ans + val) % mod;
    }

    // Multiply the accumulated answer by 'b' and take modulus
    ans = (ans * b) % mod;

    // Print the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
