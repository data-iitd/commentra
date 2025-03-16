#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define inf 1000000007 // Large constant value used as an infinite value
#define MAX_N 100000 // Maximum size for the array

int compare(const void *a, const void *b) {
    return (*(long long *)b - *(long long *)a); // Sort in descending order
}

int main() {
    int N; // Variable to store the number of elements in the array
    scanf("%d", &N); // Read the number of elements from the standard input
    long long A[MAX_N]; // Declare an array A of size MAX_N

    for(int i = 0; i < N; ++i) { // Iterate through the range [0, N) and read each element into the array
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), compare); // Sort the array A in descending order

    int index; // Variable to store the index of the second smallest element
    long long max = inf; // Initialize the maximum difference to an infinite value

    for(int i = 1; i < N; ++i) { // Iterate through the range [1, N)
        if(max > fabs(A[0] - 2 * A[i])) { // Check if the current difference is greater than the maximum difference
            max = fabs(A[0] - 2 * A[i]); // Update the maximum difference if it is
            index = i; // Update the index of the second smallest element
        }
    }

    printf("%lld %lld\n", A[0], A[index]); // Output the largest and the second largest elements
    return 0;
}

// <END-OF-CODE>
