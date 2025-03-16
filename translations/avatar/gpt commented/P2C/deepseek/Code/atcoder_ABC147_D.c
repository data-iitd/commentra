#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for the array
    int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));
    if (A == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read the input values and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    int64_t result = 0;

    // Iterate over each bit position from 0 to 59
    for (int b = 0; b < 60; b++) {
        int64_t bs = 0;

        // Count how many numbers have the b-th bit set (1)
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }

        // Calculate the contribution of the b-th bit to the result
        // bs * (N - bs) gives the number of pairs with different b-th bits
        // (1LL << b) gives the value of the b-th bit
        result = (result + bs * (N - bs) % MOD * ((int64_t)1 << b)) % MOD;
    }

    // Print the final result
    printf("%lld\n", result);

    // Free the allocated memory
    free(A);

    return 0;
}
