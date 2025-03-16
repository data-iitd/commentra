#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation and sorting

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N; // Variable to store the number of elements
    scanf("%d", &N); // Read the number of elements from standard input

    int *A = (int *)malloc(N * sizeof(int)); // Dynamically allocate memory for the array A

    // Read each element from standard input and store it in the array A
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }

    // Sort the array A in ascending order
    qsort(A, N, sizeof(int), compare);

    // Initialize variables to store the minimum and maximum elements
    int min = A[0];
    int max = A[N - 1];
    int mins = 0, maxs = 0; // Counters for occurrences of min and max

    // Iterate through each element in the array A to count occurrences of min and max
    for (int i = 0; i < N; i++) {
        if (A[i] == min) {
            mins++;
        }
        if (A[i] == max) {
            maxs++;
        }
    }

    // Check if the minimum and maximum elements are the same
    if (min == max) {
        long result = (max - min) + 1; // Calculate the difference plus 1
        result *= mins; // Multiply by the number of occurrences of the minimum element
        result -= mins * (mins - 1) / 2; // Subtract combinations of pairs of minimum elements
        printf("%ld\n", result); // Print the output
    } else {
        long result = (max - min); // Calculate the difference between min and max
        result *= mins; // Multiply by the number of occurrences of the minimum element
        result *= maxs; // Multiply by the number of occurrences of the maximum element
        printf("%ld\n", result); // Print the output
    }

    free(A); // Free the allocated memory for the array A
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
