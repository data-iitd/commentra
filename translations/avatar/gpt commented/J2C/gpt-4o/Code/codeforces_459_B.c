#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read the number of elements from input
    int N;
    scanf("%d", &N);
    
    // Initialize an array to hold the input integers
    int *A = (int *)malloc(N * sizeof(int));
    
    // Read N integers from input and store them in the array A
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }
    
    // Sort the array A to easily find the minimum and maximum values
    qsort(A, N, sizeof(int), compare);
    
    // Identify the minimum and maximum values in the sorted array
    int min = A[0];
    int max = A[N - 1];
    
    // Initialize counters for occurrences of min and max values
    long mins = 0;
    long maxs = 0;
    
    // Count how many times the minimum and maximum values occur in the array
    for (int i = 0; i < N; i++) {
        if (A[i] == min) mins++;
        if (A[i] == max) maxs++;
    }
    
    // If all elements are the same (min equals max)
    if (min == max) {
        // Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        printf("%ld %ld\n", (long)(max - min), mins * (mins - 1) / 2);
    } else {
        // Calculate the difference and the product of occurrences of min and max
        printf("%ld %ld\n", (long)(max - min), mins * maxs);
    }
    
    // Free the allocated memory
    free(A);
    
    return 0;
}

// <END-OF-CODE>
