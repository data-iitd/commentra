#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements in the list 'A'
    int N;
    scanf("%d", &N);

    // Initialize an array 'A' with the given size 'N'
    int *A = (int *)malloc(N * sizeof(int));
    
    // Read the elements into the array 'A'
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize minimum and maximum indices 'mn' and 'mx'
    int mn = N + 1, mx = -1;

    // Iterate through the array 'A' from index 0 to 'N-1'
    for (int i = 0; i < N; i++) {
        // Check if the current index 'i' is not equal to the next element
        if (i + 1 != A[i]) {
            // Update the minimum and maximum indices 'mn' and 'mx'
            if (i < mn) mn = i;
            if (i > mx) mx = i;
        }
    }

    // Check if the maximum index 'mx' is still equal to -1
    if (mx == -1) {
        // If yes, print '0 0' as the output
        printf("0 0\n");
    } else {
        // Create a new array to hold the modified list
        int *B = (int *)malloc(N * sizeof(int));
        
        // Copy elements before 'mn'
        for (int i = 0; i < mn; i++) {
            B[i] = A[i];
        }
        
        // Reverse the segment from 'mn' to 'mx'
        int k = mn;
        for (int i = mx; i >= mn; i--) {
            B[k++] = A[i];
        }
        
        // Copy elements after 'mx'
        for (int i = mx + 1; i < N; i++) {
            B[k++] = A[i];
        }

        // Check if the new array 'B' is sorted in ascending order
        int isSorted = 1;
        for (int i = 1; i < N; i++) {
            if (B[i] < B[i - 1]) {
                isSorted = 0;
                break;
            }
        }

        // Output the result based on whether 'B' is sorted
        if (isSorted) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }

        // Free the allocated memory for the new array
        free(B);
    }

    // Free the allocated memory for the original array
    free(A);
    
    return 0;
}
