#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to compute the modular inverse using the Extended Euclidean Algorithm
long long modinv(long long a, int m) {
    long long b = m;
    long long u = 1;
    long long v = 0;
    long long tmp = 0;

    // Apply the Extended Euclidean Algorithm
    while (b > 0) {
        long long t = a / b;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }

    // Ensure u is positive and within the modulus
    u %= m;
    if (u < 0) u += m;

    // Return the modular inverse
    return u;
}

int main() {
    // Read the integer n, which represents the number of elements
    int n;
    cin >> n;

    // Read the next line of input and store it in a vector
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Define a modulus value for calculations to prevent overflow
    const int mod = 1000000007;

    // Initialize a variable to hold the factorial product
    long long p = 1;

    // Calculate the factorial of n modulo mod
    for (int i = 2; i <= n; i++) {
        p = p * i % mod;
    }

    // Initialize a vector to hold cumulative sums of modular inverses
    vector<long long> q(n);
    q[0] = 1; // Base case for the first element

    // Calculate the cumulative sum of modular inverses
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }

    // Initialize a variable to hold the final answer
    long long ans = 0;

    // Calculate the final answer using the cumulative sums and input array
    for (int i = 0; i < n; i++) {
        long long val = q[i] + q[n - i - 1] - 1; // Combine values from the q array
        val *= a[i]; // Multiply by the corresponding element in a
        val %= mod; // Take modulo
        val *= p; // Multiply by the factorial product
        val %= mod; // Take modulo again
        ans += val; // Add to the final answer
        ans %= mod; // Take modulo to keep the answer manageable
    }

    // Print the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
