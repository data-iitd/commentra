#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define rep(i, n) for (int i = 0; i < (n); i++) // Define a shorthand for repetition

int main(void) {
    // Read the number of elements in the vector
    int N;
    scanf("%d", &N);

    // Initialize an array of size N with integers
    int64_t *A = (int64_t *)malloc(N * sizeof(int64_t));
    rep(i, N) { // Iterate through each element in the array and read its value
        scanf("%lld", &A[i]);
    }

    // Initialize the answer variable to 0
    int64_t answer = 0;

    // Outer loop iterates through each element in the array except the last one
    for (int i = 0; i < N - 1; ++i) {
        // Inner loop iterates through the remaining elements in the array starting from the next element
        for (int j = i + 1; j < N; ++j) {
            // Calculate the absolute difference between the current and next elements
            int64_t diff = llabs(A[i] - A[j]);

            // Update the answer variable with the maximum difference found so far
            if (diff > answer) {
                answer = diff;
            }
        }
    }

    // Print the answer
    printf("%lld\n", answer);

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
