#include <stdio.h>
#include <stdint.h>

#define MOD 1000000007

int main() {
    // Read the number of elements in the array
    int N;
    scanf("%d", &N);

    // Create an array to store the input values
    int64_t A[N];

    // Read the input values into the array
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize the result variable to store the final answer
    int64_t result = 0;

    // Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
    for (int b = 0; b < 60; b++) {
        // Count how many numbers have the b-th bit set (1)
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << b)) {
                bs++;
            }
        }

        // Calculate the contribution of the b-th bit to the result
        // bs * (N - bs) gives the number of pairs with different b-th bits
        // (1LL << b) gives the value of the b-th bit
        result = (result + (int64_t)bs * (N - bs) * (1LL << b)) % MOD;
    }

    // Print the final result
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
