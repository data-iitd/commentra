#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements in the list
    int N;
    scanf("%d", &N);

    // Allocate memory for the list of integers
    int *A = (int *)malloc(N * sizeof(int));

    // Read the list of integers from input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize minimum and maximum indices for the range of elements that are out of place
    int mn = N + 1, mx = -1;

    // Iterate through the list to find the first and last indices where the element is not in its correct position
    for (int i = 0; i < N; i++) {
        // Check if the current index + 1 does not match the value at that index
        if ((i + 1) != A[i]) {
            // Update the minimum index if the current index is less than the current minimum
            if (i < mn) mn = i;
            // Update the maximum index if the current index is greater than the current maximum
            if (i > mx) mx = i;
        }
    }

    // If no elements were out of place, output '0 0'
    if (mx == -1) {
        printf("0 0\n");
    } else {
        // Reverse the subarray from mn to mx
        for (int i = mn, j = mx; i < j; i++, j--) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

        // Check if the modified list is sorted
        int isSorted = 1;
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i - 1]) {
                isSorted = 0;
                break;
            }
        }

        // If sorted, print the 1-based indices of the range that was reversed
        if (isSorted) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            // If not sorted, output '0 0'
            printf("0 0\n");
        }
    }

    // Free allocated memory
    free(A);
    return 0;
}

// <END-OF-CODE>
