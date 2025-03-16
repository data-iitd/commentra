#include <stdio.h>
#include <stdlib.h>

// Global pointer to hold the sieve flags for prime numbers
int *flag;

// Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
void prime(int num) {
    int i, j;

    // Allocate memory for the flag array to mark non-prime numbers
    flag = (int *)calloc(sizeof(int), num + 1);

    // Implementing the Sieve of Eratosthenes
    for (i = 2; i * i <= num; i++) {
        // If the number is still marked as prime
        if (flag[i] == 0) {
            // Mark all multiples of i as non-prime
            for (j = 2; i * j <= num; j++) {
                flag[i * j] = 1; // Marking the multiple as non-prime
            }
        }
    }
}

// Main function to execute the program
int main() {
    int n, i, cnt;

    // Generate prime numbers up to 50000
    prime(50000);

    // Infinite loop to continuously accept user input
    while (1) {
        // Read an integer from the user
        scanf("%d", &n);
        // Exit the loop if the input is 0
        if (n == 0) {
            break;
        }
        
        i = 2; // Start checking from the smallest prime number
        cnt = 0; // Initialize count of valid pairs

        // Check pairs of primes that sum up to n
        while (i * 2 <= n) {
            // If both i and n-i are prime
            if (!flag[i] && !flag[n - i]) {
                cnt++; // Increment the count of valid pairs
            }
            i++; // Move to the next number
        }
        
        // Output the count of prime pairs that sum up to n
        printf("%d\n", cnt);
    }

    return 0; // Return success
}

