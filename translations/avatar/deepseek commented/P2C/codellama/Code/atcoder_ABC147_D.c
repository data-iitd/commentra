
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Read the size of the array
    int N;
    scanf("%d", &N);

    // Create a numpy array from the input values
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Initialize the result variable to 0
    long long result = 0;

    // Loop over each bit position from 0 to 59
    for (int b = 0; b < 60; b++) {
        // Count the number of set bits at the current bit position
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1 << b)) {
                bs++;
            }
        }

        // Calculate the contribution of the current bit position to the result
        result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
    }

    // Print the final result
    printf("%lld\n", result);

    return 0;
}

