#include <stdio.h>
#include <stdint.h>

#define MOD 1000000007
#define MAX_BITS 60

int main() {
    // Read the number of elements 'N' from the user
    int N;
    scanf("%d", &N);

    // Declare an array to store the integers
    int64_t A[N];

    // Read 'N' integers from the user and store them in the array 'A'
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize the result variable to zero
    int64_t result = 0;

    // Iterate through each bit position 'b' from 0 to 59
    for (int b = 0; b < MAX_BITS; b++) {
        // Calculate the sum of bits in position 'b' in all numbers of 'A'
        int64_t bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1; // Count the number of 1s in bit position 'b'
        }

        // Calculate the contribution of this bit position 'b' to the result
        int64_t contribution = bs * (N - bs) % MOD * (1LL << b) % MOD;

        // Add this contribution to the result
        result = (result + contribution) % MOD;
    }

    // Print the final result
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
