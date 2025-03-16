#include <iostream>   // For input and output
#include <vector>    // For using vector
#include <numeric>   // For std::gcd
#include <algorithm> // For std::lcm
#include <cmath>     // For std::pow
using namespace std;

typedef long long ll; // Define ll as a shorthand for long long

// Function to calculate modular inverse using Fermat's Little Theorem
ll modInv(ll x, ll mod) {
    return modPow(x, mod - 2, mod);
}

// Function to calculate power of a number using modular arithmetic
ll modPow(ll b, ll e, ll mod) {
    ll ans = 1;
    ll x = b % mod;
    while (e > 0) {
        if (e & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        e >>= 1;
    }
    return ans;
}

// Function to perform modular division
ll modDiv(ll a, ll b, ll mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N; // Number of integers
    cin >> N; // Reading the number of integers
    vector<int> A(N); // Creating a vector A of size N

    // Reading each integer in the vector A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll lcm = 1; // Initializing lcm as 1
    const ll mod = 1000000007; // Setting the modulus value

    // Calculating the least common multiple (lcm) of all integers in vector A
    for (int ai : A) {
        lcm = lcm / std::gcd(lcm, (ll)ai) * ai; // Calculating lcm using division and multiplication
    }

    ll modLcm = lcm % mod; // Calculating the remainder of lcm modulo mod
    ll ans = 0; // Initializing answer variable as 0

    // Calculating the answer using modular arithmetic
    for (int ai : A) {
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    }

    // Printing the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
