#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
#include <cmath> // for std::pow
#include <limits.h> // for LONG_MAX

using namespace std;

// Function to perform modular exponentiation
long long modPow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    for (long long y = e; y > 0; y >>= 1) {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
    }
    return ans;
}

// Function to calculate modular inverse
long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

// Function to perform modular division
long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    // Read N integers into vector A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize LCM to 1
    long long lcm = 1;

    // Calculate the LCM of all elements in vector A
    for (int ai : A) {
        long long a = ai;
        long long gcd_value = gcd(lcm, a);
        lcm = lcm / gcd_value * a;
    }

    // Define the modulo value
    long long mod = 1000000007;

    // Calculate the LCM modulo 10^9 + 7
    long long modLcm = lcm % mod;

    // Initialize the answer to 0
    long long ans = 0;

    // Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for (int ai : A)
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;

    // Print the final answer
    cout << ans << endl;

    return 0;
}
