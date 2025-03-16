#include <stdio.h>
#include <stdlib.h>

#define MX 10000

int main() {
    // Create an array 'sieve' of size MX initialized to 0
    int sieve[MX] = {0};
    // Create a dynamic array for 'primes'
    int *primes = malloc(MX * sizeof(int));
    int prime_count = 0;

    // Sieve of Eratosthenes to find all prime numbers up to MX
    for (int i = 2; i < MX; i++) {
        if (sieve[i] != 0) {
            continue;
        }
        // If 'sieve[i]' is zero, then 'i' is a prime number
        primes[prime_count++] = i;

        // Mark all multiples of 'i' as composite
        for (int j = i + i; j < MX; j += i) {
            sieve[j] = i;
        }
    }

    // Read an integer 'n' from standard input
    int n;
    scanf("%d", &n);

    // Initialize 'ans' to count numbers that are not composite
    int ans = 0;

    // Read 'n' integers from standard input
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        // Increment 'ans' as 'x' is not composite at this point
        ans++;

        // Check if 'x' is divisible by any prime number
        for (int j = 0; j < prime_count; j++) {
            if (x > primes[j] && x % primes[j] == 0) {
                ans--;
                break;
            }
        }
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free the allocated memory for primes
    free(primes);

    return 0;
}

// <END-OF-CODE>
