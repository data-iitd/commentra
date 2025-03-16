#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to calculate GCD
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate LCM
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// Function to perform modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
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

    // Read N integers into array A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize LCM to 1
    long long lcmValue = 1;

    // Calculate the LCM of all elements in array A
    for (int ai : A) {
        lcmValue = lcm(lcmValue, ai);
    }

    // Define the modulo value
    long long mod = 1000000007;

    // Calculate the LCM modulo 10^9 + 7
    long long modLcm = lcmValue % mod;

    // Initialize the answer to 0
    long long ans = 0;

    // Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for (int ai : A) {
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
