#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MX 10000

bool is_prime(int x, int *primes, int prime_count) {
    for (int i = 0; i < prime_count; i++) {
        if (primes[i] * primes[i] > x) {
            break;
        }
        if (x % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int sieve[MX] = {0};
    int primes[MX] = {0};
    int prime_count = 0;

    // Use the Sieve of Eratosthenes to find all primes up to MX
    for (int i = 2; i < MX; i++) {
        if (sieve[i] != 0) {
            continue; // Skip if i is not a prime
        }
        primes[prime_count++] = i; // i is a prime, add it to the primes list
        for (int j = i + i; j < MX; j += i) {
            sieve[j] = i; // Mark j as not prime
        }
    }

    // Read the number of integers to process
    int n;
    scanf("%d", &n);
    int ans = 0;

    // Process each integer and update the answer
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans++; // Assume the number is valid
        if (!is_prime(x, primes, prime_count)) {
            ans--; // The number is not valid
        }
    }

    // Output the result
    printf("%d\n", ans);

    return 0;
}
