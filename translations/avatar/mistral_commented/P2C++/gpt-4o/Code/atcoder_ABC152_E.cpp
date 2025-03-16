#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

// Function to calculate the least common multiple of two numbers a and b.
long long lcm(long long a, long long b) {
    return a / std::gcd(a, b) * b; // Using std::gcd to calculate the greatest common divisor
}

const long long MOD = 1000000007;

int main() {
    int N;
    cin >> N; // Reading the input N
    vector<long long> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Storing the list A of N integers
    }

    long long _lcm = 1; // Initializing the variable _lcm to 1

    // Iterating through each number a in the list A and updating the value of _lcm
    for (long long a : A) {
        _lcm = lcm(_lcm, a); // Update the value of _lcm using the lcm function
    }

    // Calculating the answer ans
    long long ans = _lcm;
    for (long long s : A) {
        ans = (ans * pow(s, MOD - 2, MOD)) % MOD; // Using modular exponentiation
    }

    // Printing the final answer
    cout << (ans % MOD) << endl;

    return 0;
}

// Function to perform modular exponentiation
long long pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }
    return result;
}

// <END-OF-CODE>
