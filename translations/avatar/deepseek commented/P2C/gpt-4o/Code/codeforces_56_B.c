#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);  // Read the integer input N
    int *A = (int *)malloc(N * sizeof(int));  // Allocate memory for the list of integers A

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);  // Read the list of integers A
    }

    // Initialize variables to track the minimum and maximum indices where the condition is true
    int mn = N + 1, mx = -1;

    // Iterate over the range of N to find the indices where the condition is true
    for (int i = 0; i < N; i++) {
        if ((i + 1) != A[i]) {
            if (i < mn) mn = i;  // Update mn if a smaller index is found
            if (i > mx) mx = i;  // Update mx if a larger index is found
        }
    }

    // Check if no indices satisfy the condition
    if (mx == -1) {
        printf("0 0\n");  // Print '0 0' if no indices satisfy the condition
    } else {
        // Reverse the sublist from index mn to mx + 1
        for (int i = mn, j = mx; i < j; i++, j--) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

        // Check if the list A is sorted
        int isSorted = 1;
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i - 1]) {
                isSorted = 0;
                break;
            }
        }

        if (isSorted) {
            printf("%d %d\n", mn + 1, mx + 1);  // Print the indices if A is sorted
        } else {
            printf("0 0\n");  // Print '0 0' if A is not sorted
        }
    }

    free(A);  // Free the allocated memory
    return 0;
}
