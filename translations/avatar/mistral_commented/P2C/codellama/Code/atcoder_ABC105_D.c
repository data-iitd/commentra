#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the count of elements having the same remainder
typedef struct {
    int remainder;
    int count;
} remainder_count;

// Function to calculate the number of combinations of elements having the same remainder
int combinations(int *A, int N, int M) {
    // Initialize an array to store the count of elements having the same remainder
    remainder_count *remainder_counts = (remainder_count *)malloc(M * sizeof(remainder_count));

    // Initialize the count of elements having the same remainder to 0
    for (int i = 0; i < M; i++) {
        remainder_counts[i].remainder = i;
        remainder_counts[i].count = 0;
    }

    // Calculate the cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
    int cum_remainders[N];
    cum_remainders[0] = A[0] % M;
    for (int i = 1; i < N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i]) % M;
    }

    // Count the occurrences of each cumulative remainder
    for (int i = 0; i < N; i++) {
        remainder_counts[cum_remainders[i]].count++;
    }

    // Calculate the number of combinations of elements having the same remainder
    int combinations = 0;
    for (int i = 0; i < M; i++) {
        combinations += remainder_counts[i].count * (remainder_counts[i].count - 1) / 2;
    }

    // Free the memory allocated to the array
    free(remainder_counts);

    // Return the number of combinations
    return combinations;
}

// Main function
int main() {
    // Read the number of rows and columns
    int N, M;
    scanf("%d %d", &N, &M);

    // Read the elements of the array
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate the number of combinations of elements having the same remainder
    int result = combinations(A, N, M);

    // Print the result
    printf("%d\n", result);

    // End of code
    return 0;
}

