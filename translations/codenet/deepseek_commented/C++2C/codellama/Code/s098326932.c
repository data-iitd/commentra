
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define INF 1e18+1

// Function to calculate the minimum n/S(n)
long long f(long long N) {
    long long a[20] = {0}; // Vector to store digits of N
    long long d = 0; // Digit counter
    while (N > 0) {
        a[d] = N % 10; // Store the last digit of N
        N /= 10; // Remove the last digit from N
        d++; // Increment the digit counter
    }
    double m = 1e18; // Initialize the minimum fraction to a large number
    long long res = N; // Initialize the result to 0
    for (int i = 0; i <= d; i++) {
        long long bunsi = 0; // Numerator
        long long bunbo = 9 * i; // Denominator
        for (int j = d-1; j >= 0; j--) {
            bunsi *= 10;
            if (j < i) bunsi += 9; // Add 9 to the current digit if necessary
            else bunsi += a[j]; // Add the actual digit
            
            if (j >= i) bunbo += a[j]; // Add the actual digit to the denominator if necessary
            
        }
        //printf("bb%lld %lld  \n", bunsi, bunbo);
        double frac = (double) bunsi / (double) bunbo; // Calculate the fraction
        if (frac < m) {
            m = frac; // Update the minimum fraction
            res = bunsi; // Update the result
        }
    }
    return res; // Return the result
}

int main() {
    long long K;
    scanf("%lld", &K); // Read the number of iterations
    long long N = f(1); // Initialize N with the result of f(1)
    for (long long i = 0; i < K; i++) {
        printf("%lld\n", N); // Output the current N
        N = f(N+1); // Update N to the result of f(N+1)
    }
    

}

// 