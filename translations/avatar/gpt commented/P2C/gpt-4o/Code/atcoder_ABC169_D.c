#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define INF 999999999999999999LL
#define MOD 1000000007

// Function to read a single integer from input
int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to perform prime factorization of a number
void prime_factorize(long long n, int *factors, int *count) {
    // Count of factors
    *count = 0;

    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        factors[(*count)++] = 2;
        n /= 2;
    }

    // Check for odd factors from 3 upwards
    for (long long f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            factors[(*count)++] = f;
            n /= f;
        }
    }

    // If n is still greater than 1, it is a prime factor
    if (n > 1) {
        factors[(*count)++] = n;
    }
}

int main() {
    // Read an integer 'n' from input
    int n = read_int();

    // If n is 1, print 0 and exit
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    // Array to store prime factors
    int factors[100]; // Assuming a maximum of 100 factors for simplicity
    int count = 0;

    // Perform prime factorization on n
    prime_factorize(n, factors, &count);

    // Count the occurrences of each prime factor
    int fac[100] = {0}; // Array to count occurrences of each prime factor
    int unique_factors = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < unique_factors; j++) {
            if (fac[j] == factors[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            fac[unique_factors++] = factors[i];
        }
    }

    // Initialize the answer variable
    long long ans = 0;

    // Calculate the number of ways to express the prime factors
    for (int i = 0; i < unique_factors; i++) {
        int x = 0;
        for (int j = 0; j < count; j++) {
            if (factors[j] == fac[i]) {
                x++;
            }
        }
        // For each prime factor's exponent, calculate how many times it can be used
        for (int j = 1; j < 99999999; j++) {
            if (x >= j) {
                x -= j;
                ans++;
            } else {
                break;
            }
        }
    }

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
