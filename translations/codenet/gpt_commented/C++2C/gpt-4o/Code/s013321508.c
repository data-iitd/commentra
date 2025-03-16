#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Declare variables for the number of elements (N) and the number of operations (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize an array to hold the elements
    int *L = (int *)malloc(N * sizeof(int));
    
    // Read N integers from input and store them in the array L
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Sort the array L in ascending order
    qsort(L, N, sizeof(int), compare);

    // Perform M operations to modify the array L
    for (int i = 0; i < M; i++) {
        // Get the maximum element from the end of the sorted array
        int max_L = L[N - 1];
        
        // If the maximum element is 0, break the loop as no further operations are needed
        if (max_L == 0) {
            break;
        }

        // Halve the maximum element
        max_L /= 2;

        // Insert the halved value into the array at the correct position
<<<<<<< HEAD
        // Remove the last element (the original maximum) from the array
        L[N - 1] = max_L;

        // Sort the array again after modification
        qsort(L, N, sizeof(int), compare);
=======
        // First, we need to find the position to insert the halved value
        int pos = 0;
        while (pos < N && L[pos] < max_L) {
            pos++;
        }

        // Shift elements to the right to make space for the new element
        for (int j = N; j > pos; j--) {
            L[j] = L[j - 1];
        }
        L[pos] = max_L; // Insert the halved value
        N--; // Decrease the size of the array as we removed the last element
>>>>>>> 98c87cb78a (data updated)
    }

    // Calculate the sum of all elements in the array L
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    // Output the final sum
    printf("%lld\n", ans);

    // Free the allocated memory
    free(L);

    return 0;
}

// <END-OF-CODE>
