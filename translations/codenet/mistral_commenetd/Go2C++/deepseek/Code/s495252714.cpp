#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Constants
const long long mod = 1000000007;

// Function to calculate modular exponentiation
long long modpow(long long a, long long n) {
    // Initialize result to 1
    long long res = 1;

    // If n is 0, return result
    if (n == 0) return res;

    // If n is 1, return a
    if (n == 1) return a;

    // If n is odd, multiply result with a multiplied by itself recursively
    if (n & 1) {
        res = res * a % mod;
        a = a * a % mod;
        n = n >> 1;
        res = res * modpow(a, n) % mod;
    }

    // If n is even, square result and recursively call function for n/2
    else {
        a = a * a % mod;
        n = n >> 1;
        res = modpow(a, n) % mod;
    }

    // Return result
    return res;
}

int main() {
    // Read an integer n from standard input
    int n;
    cin >> n;

    // Read n integers c from standard input and store them in a vector
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Sort vector c in ascending order
    sort(c.begin(), c.end());

    // Initialize answer variable to 0
    long long ans = 0;

    // Iterate through vector c and calculate answer
    for (int i = 0; i < n; i++) {
        // Calculate contribution of current integer to answer
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
    }

    // Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
    cout << ans * modpow(4, n - 1) % mod << endl;

    return 0;
}

