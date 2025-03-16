#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

// Define a long long type for convenience
typedef long long ll;

// Function to update a variable to the maximum of itself and another value
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b; 
        return 1;
    } 
    return 0;
}

// Function to update a variable to the minimum of itself and another value
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b; 
        return 1;
    } 
    return 0;
}

// Define a constant for infinity
const ll INF = 1e18 + 1;

/*
The following comments explain the logic behind the function f(N) and the overall approach.
1. The goal is to find the smallest integer n >= N such that n/S(n) is minimized.
2. The function f(N) computes candidates for this minimization by manipulating the digits of N.
*/

// Function to find the smallest integer n >= N such that n/S(n) is minimized
ll f(ll N) {
    // Array to store the digits of N
    vector<ll> a(20, 0);
    ll d = 0; // Digit counter

    // Extract digits of N and store them in the array
    while (N > 0) {
        a[d] = N % 10; // Get the last digit
        N /= 10; // Remove the last digit
        d++; // Increment digit counter
    }

    double m = 1e18; // Initialize minimum fraction to a large value
    ll res = N; // Result variable to store the best candidate

    // Iterate through possible positions to replace digits with 9s
    for (int i = 0; i <= d; i++) {
        ll bunsi = 0; // Numerator
        ll bunbo = 9 * i; // Denominator starts with 9 times the number of replaced digits

        // Construct the numerator and denominator based on the current digit manipulation
        for (int j = d - 1; j >= 0; j--) {
            bunsi *= 10; // Shift left for the next digit
            if (j < i) 
                bunsi += 9; // Replace with 9 if below the current index
            else 
                bunsi += a[j]; // Keep the original digit
            
            if (j >= i) 
                bunbo += a[j]; // Add to denominator if the digit is not replaced
        }

        // Calculate the fraction n/S(n)
        double frac = (double)bunsi / (double)bunbo;

        // Update the result if a new minimum fraction is found
        if (frac < m) {
            m = frac; // Update minimum fraction
            res = bunsi; // Update result with the new candidate
        }
    }
    return res; // Return the best candidate found
}

int main() {
    ll K; // Number of outputs to generate
    cin >> K; // Read the number of outputs

    ll N = f(1); // Initialize N by finding the first candidate starting from 1

    // Generate K outputs
    for (ll i = 0; i < K; i++) {
        cout << N << endl; // Output the current candidate
        N = f(N + 1); // Find the next candidate starting from N + 1
    }
}
