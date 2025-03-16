#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to compute the greatest common divisor (GCD)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the least common multiple (LCM)
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

// Function to compute modular inverse using Fermat's Little Theorem
long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

// Function to perform modular division
long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    // Create a variable to read the number of elements N
    int N;
    cin >> N;

    // Initialize a vector to hold N integers
    vector<int> A(N);

    // Read N integers into the vector A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize a variable to calculate the least common multiple (LCM)
    long long lcmValue = 1;

    // Calculate the LCM of all elements in the vector A
    for (int ai : A) {
        lcmValue = lcm(lcmValue, ai);
    }

    // Define the modulus value
    long long mod = 1000000007;

    // Calculate the LCM modulo mod
    long long modLcm = lcmValue % mod;

    // Initialize the answer variable to accumulate results
    long long ans = 0;

    // Calculate the sum of modDiv for each element in A
    for (int ai : A) {
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    }

    // Print the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
