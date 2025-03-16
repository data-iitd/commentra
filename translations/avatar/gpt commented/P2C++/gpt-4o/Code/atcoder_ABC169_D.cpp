#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// Function to read a single integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to perform prime factorization of a number
vector<int> primeFactorize(int n) {
    vector<int> factors;
    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    
    // Check for odd factors from 3 upwards
    for (int f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            factors.push_back(f);
            n /= f;
        }
    }
    
    // If n is still greater than 1, it is a prime factor
    if (n > 1) {
        factors.push_back(n);
    }
    
    return factors;
}

int main() {
    // Read an integer 'n' from input
    int n = readInt();

    // If n is 1, print 0 and exit
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Perform prime factorization on n
    vector<int> fac_ = primeFactorize(n);

    // Count the occurrences of each prime factor
    map<int, int> fac;
    for (int f : fac_) {
        fac[f]++;
    }

    // Initialize the answer variable
    long long ans = 0;

    // Calculate the number of ways to express the prime factors
    for (const auto& [p, e] : fac) {
        int x = e;
        // For each prime factor's exponent, calculate how many times it can be used
        for (int i = 1; i < 99999999; ++i) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
