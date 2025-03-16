#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Read the number of elements 'N' from the user
    int N;
    scanf("%d", &N);

    // Read 'N' integers from the user and store them in a NumPy array 'A'
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize the result variable to zero
    int result = 0;

    // Iterate through each bit position 'b' from 0 to 59
    for (int b = 0; b < 60; b++) {

        // Calculate the sum of bits in position 'b' in all numbers of 'A'
        int bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }

        // Calculate the contribution of this bit position 'b' to the result
        int contribution = bs * (N - bs) * (1 << b);

        // Add this contribution to the result
        result = (result + contribution) % 1000000007;
    }

    // Print the final result
    printf("%d", result);

    return 0;
}
