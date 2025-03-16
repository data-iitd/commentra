#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Define long long type for large integers
typedef long long ll;

// Define constants for modulo operations and maximum size
const int mod = 1e9 + 7;
const int NMAX = 1000010;

// Arrays to store factorials, inverse factorials, and modular inverses
ll fac[NMAX], finv[NMAX], inv[NMAX];

// Function to initialize factorials and their inverses
void init() {
    // Base cases for factorials and their inverses
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    // Precompute factorials and their modular inverses
    for(int i = 2; i < NMAX; i++) {
        fac[i] = fac[i - 1] * i % mod; // Compute factorial mod
        inv[i] = mod - inv[mod % i] * (mod / i) % mod; // Compute modular inverse using Fermat's little theorem
        finv[i] = finv[i - 1] * inv[i] % mod; // Compute inverse factorial mod
    }
}

// Function to compute binomial coefficient C(n, k)
ll C(int n, int k) {
    // Return 0 if k is greater than n or if either is negative
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;

    // Calculate C(n, k) using precomputed factorials and inverses
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
    // Initialize factorials and inverses
    init();

    // Read input values for X and Y
    int X, Y; 
    cin >> X >> Y;

    // Check if the sum of X and Y is divisible by 3
    if((X + Y) % 3 != 0) {
        cout << 0 << endl; // If not, output 0 and exit
        return 0;
    }

    // Calculate n based on the sum of X and Y
    int n = (X + Y) / 3 + 1;

    // Calculate k based on the relationship to the line y = 2x
    int k = 2 * (n - 1) - Y + 1; // Determine how far the point is from the topmost point

    // Output the result of the binomial coefficient C(n-1, k-1)
    cout << C(n - 1, k - 1) << endl;

    return 0; // End of the program
}

