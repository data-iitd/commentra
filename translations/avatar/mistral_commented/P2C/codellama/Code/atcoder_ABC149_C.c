#include <stdio.h>

// Initialize an array 'prime' of boolean values with all elements as True
// The array 'prime' will be used to store whether a number is prime or not
// The size of the array is 100010
int prime[100010] = {1};

// Set the first two elements of the array as False, as 0 and 1 are not prime numbers
prime[0] = 0;
prime[1] = 0;

// Sieve of Eratosthenes algorithm to find prime numbers up to 100008
for (int i = 4; i <= 100008; i += 2) {
    // If the number 'i' is prime
    if (prime[i]) {
        // Mark all multiples of 'i' as composite (non-prime)
        for (int j = i + i; j <= 100008; j += i) {
            prime[j] = 0;
        }
    }
}

// Find the prime number 'X' and print it
int i = X;
while (i <= 100008) {
    // If the number 'i' is prime
    if (prime[i]) {
        printf("%d\n", i);
        // Exit the loop as we have found the prime number 'X'
        break;
    }
    i++;
}

