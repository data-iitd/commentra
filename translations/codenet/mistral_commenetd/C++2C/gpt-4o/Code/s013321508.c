#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, M; // Initialize two integers to read input from user

    // Read input from user
    scanf("%d %d", &N, &M);

    // Initialize an array of integers with size N
    int *L = (int *)malloc(N * sizeof(int));

    // Read integers from user and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]); // Read an integer and store it in the array
    }

    // Sort the array in ascending order
    qsort(L, N, sizeof(int), compare);

    // Perform the required operations for M times
    for (int i = 0; i < M; i++) {
        int max_L = L[N - 1]; // Get the last element of the array

        // If the last element is 0, break the loop
        if (max_L == 0) {
            break;
        }

        // Divide the last element by 2
        max_L /= 2;

        // Find the position to insert max_L
        int *itr = (int *)bsearch(&max_L, L, N, sizeof(int), compare);
        int insert_index;

        if (itr) {
            insert_index = (itr - L);
        } else {
            insert_index = N; // If not found, insert at the end
        }

        // Resize the array to make space for the new element
        L = (int *)realloc(L, (N + 1) * sizeof(int));

        // Shift elements to the right to make space for max_L
        for (int j = N; j > insert_index; j--) {
            L[j] = L[j - 1];
        }

        // Insert max_L before the found position
        L[insert_index] = max_L;
        N--; // Remove the last element
    }

    // Calculate the answer
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    // Print the answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(L);

    return 0;
}

// <END-OF-CODE>
