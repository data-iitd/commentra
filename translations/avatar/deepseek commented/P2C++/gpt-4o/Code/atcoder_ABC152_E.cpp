#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
using namespace std;

// Function to calculate the least common multiple (LCM) of two numbers
long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b)); // Using the gcd function to calculate the LCM
}

const int MOD = 1e9 + 7; // Define a constant MOD for modulo operations

int main() {
    int N; // Number of elements in the list A
    cin >> N; // Read the number of elements
    vector<long long> A(N); // Vector to store the elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read the list A as integers
    }

    long long _lcm = 1; // Initialize _lcm to 1
    for (long long a : A) {
        _lcm = lcm(_lcm, a); // Update _lcm to be the LCM of _lcm and the current element
    }

    // Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
    long long ans = _lcm; // Start with _lcm
    for (long long s : A) {
        ans = (ans + (s % MOD) * pow(s, MOD - 2, MOD) % MOD) % MOD; // Modular inverse using Fermat's little theorem
    }

    cout << ans % MOD << endl; // Print the result, ensuring it is within the modulo range
    return 0;
}

// Function to calculate power with modulo
long long pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// <END-OF-CODE>
