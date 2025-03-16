#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize variables
    int N, T; // N is the number of elements in the array A, T is an input value

    // Read input values from the standard input
    scanf("%d %d", &N, &T);

    // Allocate memory for an integer array A of size N
    int *A = (int *)malloc(N * sizeof(int));

    // Allocate memory for an integer array B of size N
    int *B = (int *)malloc(N * sizeof(int));

    // Read integer values from the standard input and store them in array A
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize variable m with the minimum value among the first two elements of array A
    int m = A[0];
    if(A[1] < m) m = A[1];

    // Set the first element of array B with the difference between the second element of array A and the initialized value of m
    B[1] = A[1] - m;

    // Iterate through the remaining elements of array A starting from the third one
    for(int i = 2; i < N; i++) {
        // Update the value of m with the minimum value between it and the current element of array A
        m = (m < A[i]) ? m : A[i];

        // Set the current element of array B with the difference between the current element of array A and the updated value of m
        B[i] = A[i] - m;
    }

    // Find the maximum element in array B
    int max_value = B[0];
    for(int i = 1; i < N; i++) {
        if(B[i] > max_value) {
            max_value = B[i];
        }
    }

    // Count occurrences of max_value in array B
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(B[i] == max_value) {
            count++;
        }
    }

    // Print the output value to the standard output
    printf("%d\n", count);

    // Free allocated memory
    free(A);
    free(B);

    // End of main function
    return 0;
}

// <END-OF-CODE>
