#include <stdio.h>
#include <stdint.h>

#define MOD 1000000007

int main() {
    // Read the size of the array
    int N;
    scanf("%d", &N);

    // Create an array to hold the input values
    int64_t A[N];
    
    // Read the input values into the array
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize the result variable to 0
    int64_t result = 0;

    // Loop over each bit position from 0 to 59
    for (int b = 0; b < 60; b++) {
        // Count the number of set bits at the current bit position
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << b)) {
                bs++;
            }
        }

        // Calculate the contribution of the current bit position to the result
        result = (result + (int64_t)bs * (N - bs) * (1LL << b)) % MOD;
    }

    // Print the final result
    printf("%lld\n", result);

    return 0;
}

// <END-OF-CODE>
