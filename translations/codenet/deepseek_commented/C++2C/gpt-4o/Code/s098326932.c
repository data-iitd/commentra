#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

// Function to calculate the minimum n/S(n)
ll f(ll N) {
    ll a[20] = {0}; // Array to store digits of N
    ll d = 0; // Digit counter
    while (N > 0) {
        a[d] = N % 10; // Store the last digit of N
        N /= 10; // Remove the last digit from N
        d++; // Increment the digit counter
    }
    double m = 1e18; // Initialize the minimum fraction to a large number
    ll res = N; // Initialize the result to 0
    for (int i = 0; i <= d; i++) {
        ll bunsi = 0; // Numerator
        ll bunbo = 9 * i; // Denominator
        for (int j = d - 1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9; // Add 9 to the current digit if necessary
            else bunsi += a[j]; // Add the actual digit
            
            if (j >= i) bunbo += a[j]; // Add the actual digit to the denominator if necessary
        }
<<<<<<< HEAD
        double frac = (double) bunsi / (double) bunbo; // Calculate the fraction
=======
        double frac = (double)bunsi / (double)bunbo; // Calculate the fraction
>>>>>>> 98c87cb78a (data updated)
        if (frac < m) {
            m = frac; // Update the minimum fraction
            res = bunsi; // Update the result
        }
    }
    return res; // Return the result
}

int main() {
    ll K;
    scanf("%lld", &K); // Read the number of iterations
    ll N = f(1); // Initialize N with the result of f(1)
    for (ll i = 0; i < K; i++) {
        printf("%lld\n", N); // Output the current N
        N = f(N + 1); // Update N to the result of f(N + 1)
    }
    
<<<<<<< HEAD
    return 0; // Return success
=======
    return 0; // End of main function
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
