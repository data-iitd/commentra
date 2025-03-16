#include <stdio.h>
#include <stdlib.h>

#define MX 10000

int main() {
    // Initialize constants and arrays
    int sieve[MX] = {0};
    int *primes = malloc(MX * sizeof(int));
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
        for (int j = 0; j < prime_count; j++) {
            if (x > primes[j] && x % primes[j] == 0) {
                ans--; // The number is not valid
                break;
            }
        }
    }

    // Output the result
    printf("%d\n", ans);

    // Free allocated memory
    free(primes);
    
    return 0;
}

// <END-OF-CODE>
