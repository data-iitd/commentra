#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(long long *)b - *(long long *)a); // Sort in descending order
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements in the array A
    long long *A = (long long *)malloc(N * sizeof(long long)); // Dynamically allocate memory for the array A
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]); // Read the elements of the array A
    }
    
    qsort(A, N, sizeof(long long), compare); // Sort the array A in descending order

    int index = -1;
    long long max = 1000000007; // Initialize max with a large value
    for(int i = 1; i < N; ++i) { // Iterate through the array to find the optimal pair
        if(max > abs(A[0] - 2 * A[i])) { // Check if the current difference is smaller than the previous minimum
            max = abs(A[0] - 2 * A[i]); // Update the minimum difference
            index = i; // Store the index of the current element
        }
    }
    
    printf("%lld %lld\n", A[0], A[index]); // Output the first and the found optimal pair

    free(A); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
