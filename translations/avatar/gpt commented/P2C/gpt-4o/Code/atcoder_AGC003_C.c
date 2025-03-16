#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read an integer N from user input
    int N;
    scanf("%d", &N);

    // Create a list A where each element is calculated as (input value * N + index)
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        int input_value;
        scanf("%d", &input_value);
        A[i] = input_value * N + i;
    }

    // Sort the list A in ascending order
    qsort(A, N, sizeof(int), compare);

    // Initialize a counter to keep track of mismatches
    int cnt = 0;

    // Iterate through each element in the sorted list A
    for (int i = 0; i < N; i++) {
        // Calculate the value of d as the remainder of A[i] divided by N, then take that remainder modulo 2
        int d = (A[i] % N) % 2;

        // Check if the parity of d does not match the parity of the current index i
        if (d % 2 != i % 2) {
            // If they don't match, increment the counter
            cnt++;
        }
    }

    // Print half of the count of mismatches, as each mismatch can be paired
    printf("%d\n", cnt / 2);

    // Free allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
