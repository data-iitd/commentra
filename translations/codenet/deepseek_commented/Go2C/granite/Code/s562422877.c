
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements N
    int N;
    scanf("%d", &N);

    // Create an array A to store N integers
    int *A = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        // Read each integer and store it in array A
        scanf("%d", &A[i]);
    }

    // Sort the array A in ascending order
    qsort(A, N, sizeof(int), cmpfunc);

    // Initialize the answer variable to store the result
    int ans = 0;
    for (int i = 1; i < N; i++) {
        // Calculate the sum of differences between consecutive elements
        ans += A[i] - A[i-1];
    }

    // Print the result
    printf("%d\n", ans);

    // Free the memory allocated for array A
    free(A);

    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

