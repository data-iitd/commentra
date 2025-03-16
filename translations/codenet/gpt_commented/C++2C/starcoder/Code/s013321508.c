#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

int main() {
    // Declare variables for the number of elements (N) and the number of operations (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize a vector to hold the elements, with a size of 100000
    int L[100000];
    int l;

    // Read N integers from input and store them in the vector L
    for (int i = 0; i < N; i++) {
        scanf("%d", &l);
        L[i] = l;
    }

    // Sort the vector L in ascending order
    qsort(L, N, sizeof(int), NULL);

    // Declare an iterator for the vector
    int *itr;

    // Perform M operations to modify the vector L
    for (int i = 0; i < M; i++) {
        // Get the maximum element from the end of the sorted vector
        int max_L = L[N - 1];
        
        // If the maximum element is 0, break the loop as no further operations are needed
        if (max_L == 0) {
            break;
        }

        // Halve the maximum element
        max_L /= 2;

        // Find the position to insert the halved value in the sorted vector
        itr = (int *)bsearch(&max_L, L, N, sizeof(int), NULL);
        
        // Insert the halved value into the vector at the found position
        L = (int *)realloc(L, (N + 1) * sizeof(int));
        memmove(itr + 1, itr, (N - (itr - L)) * sizeof(int));
        *itr = max_L;
        
        // Remove the last element (the original maximum) from the vector
        L = (int *)realloc(L, (N - 1) * sizeof(int));
        N--;
    }

    // Calculate the sum of all elements in the vector L
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    // Output the final sum
    printf("%lld\n", ans);
}

