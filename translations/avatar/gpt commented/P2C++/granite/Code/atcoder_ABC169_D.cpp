
#include <bits/stdc++.h>
using namespace std;

// Define a large constant for infinity
#define INF 999999999999999999999999

// Define a modulus constant for calculations
#define MOD 100000007

// Read an integer 'n' from input
int n;
cin >> n;

// If n is 1, print 0 and exit
if (n == 1) {
    cout << 0 << endl;
    return 0;
}

// Function to perform prime factorization of a number
vector<int> prime_factorize(int n) {
    vector<int> a;
    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        a.push_back(2);
        n /= 2;
    }
    
    // Check for odd factors from 3 upwards
    for (int f = 3; f * f <= n; f += 2) {
        if (n % f == 0) {
            a.push_back(f);
            n /= f;
        }
    }
    
    // If n is still greater than 1, it is a prime factor
    if (n!= 1) {
        a.push_back(n);
    }
    
    return a;
}

// Perform prime factorization on n
vector<int> fac = prime_factorize(n);

// Count the occurrences of each prime factor
map<int, int> fac_;
for (int p : fac) {
    fac_[p]++;
}

// Initialize the answer variable
int ans = 0;

// Calculate the number of ways to express the prime factors
for (auto [p, e] : fac_) {
    int x = e;
    // For each prime factor's exponent, calculate how many times it can be used
    for (int i = 1; i < 99999999; i++) {
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

