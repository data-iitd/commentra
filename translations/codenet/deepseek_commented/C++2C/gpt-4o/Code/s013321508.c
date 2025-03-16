#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // Reading two integers, N and M.

<<<<<<< HEAD
    int *L = (int *)malloc(100000 * sizeof(int)); // Allocating memory for an array L.
=======
    int *L = (int *)malloc(N * sizeof(int)); // Dynamically allocating memory for the array L.
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]); // Reading N integers and populating the array L.
    }

    qsort(L, N, sizeof(int), compare); // Sorting the array L in ascending order.

    for (int i = 0; i < M; i++) { // Performing M operations.
        int max_L = L[N - 1]; // Finding the largest element in the array.
        if (max_L == 0) {
            break; // If the largest element is 0, break the loop.
        }

        max_L /= 2; // Halving the largest element.
<<<<<<< HEAD
        
        // Inserting the halved value back into the array.
        // We need to find the position to insert the halved value.
        int *itr = (int *)bsearch(&max_L, L, N, sizeof(int), compare);
        if (itr == NULL) {
            // If not found, we need to find the correct position to insert.
            itr = L + N; // Start at the end of the array.
            while (itr > L && *(itr - 1) > max_L) {
                itr--;
            }
        }

        // Shift elements to make space for the new element.
        for (int j = N; j > (itr - L); j--) {
            L[j] = L[j - 1];
        }
        *itr = max_L; // Insert the halved value.
        N--; // Decrease the size of the array since we removed the largest element.
    }

    long long ans = 0; // Initialize the sum.
=======

        // Inserting the halved value back into the array.
        L[N - 1] = max_L; // Replace the largest element with the halved value.
        
        // Re-sort the array after modification.
        qsort(L, N, sizeof(int), compare); // Sorting again to maintain order.
    }

    long long ans = 0; // Variable to hold the sum of elements.
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        ans += L[i]; // Calculating the sum of all elements in the array L.
    }

    printf("%lld\n", ans); // Printing the result.

    free(L); // Freeing the allocated memory.
    return 0;
}

// <END-OF-CODE>
