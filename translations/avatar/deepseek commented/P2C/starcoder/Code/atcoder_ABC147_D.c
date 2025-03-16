#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Read the size of the array
    int N;
    scanf("%d", &N);

    // Create a numpy array from the input values
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize the result variable to 0
    int result = 0;

    // Loop over each bit position from 0 to 59
    for (int b = 0; b < 60; b++) {
        // Count the number of set bits at the current bit position
        int bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }

        // Calculate the contribution of the current bit position to the result
        result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
    }

    // Print the final result
    printf("%d", result);

    return 0;
}

