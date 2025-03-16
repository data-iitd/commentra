#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Read the number of elements in the array
    int N;
    scanf("%d", &N);

    // Read the input values and create a NumPy array of integers
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize the result variable to store the final answer
    int result = 0;

    // Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
    for (int b = 0; b < 60; b++) {
        // Count how many numbers have the b-th bit set (1)
        int bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }

        // Calculate the contribution of the b-th bit to the result
        // bs * (N - bs) gives the number of pairs with different b-th bits
        // (1 << b) gives the value of the b-th bit
        result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
    }

    // Print the final result
    printf("%d\n", result);

    return 0;
}
