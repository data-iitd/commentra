#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements in the list A

    int *A = (int *)malloc(N * sizeof(int)); // Dynamically allocate memory for the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); // Read N integers into the array A
    }

    // Remove consecutive duplicates
    int *B = (int *)malloc(N * sizeof(int)); // Temporary array to store unique elements
    int unique_count = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1]) {
            B[unique_count++] = A[i]; // Store unique elements
        }
    }

    free(A); // Free the original array A
    A = B; // Point A to the new array with unique elements
    N = unique_count; // Update N to the number of unique elements

    int ans = 0; // Initialize answer counter
    for (int i = 1; i < N - 1; i++) {
        // Check if the current element A[i] is sandwiched between two larger or smaller elements
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++; // Increment the answer counter
            i++; // Skip the next element
        }
    }

    printf("%d\n", ans + 1); // Print the final answer, which is the number of sandwiched elements plus one

    free(A); // Free the allocated memory for A
    return 0;
}
