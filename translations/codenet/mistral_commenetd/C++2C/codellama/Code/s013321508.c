
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Main function starts here
int main() {

    int N, M; // Initialize two integers to read input from user

    // Read input from user
    scanf("%d %d", &N, &M);

    // Initialize a vector of integers with size N
    int *L = (int *)malloc(N * sizeof(int));

    // Read integers from user and store them in the vector
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]); // Read an integer and store it in the vector
    }

    // Sort the vector in ascending order
    qsort(L, N, sizeof(int), compare);

    // Iterator to traverse the vector
    int *itr;

    // Perform the required operations for M times
    for (int i = 0; i < M; i++) {
        int max_L = L[N - 1]; // Get the last element of the vector

        // If the last element is 0, break the loop
        if (max_L == 0) {
            break;
        }

        // Divide the last element by 2
        max_L /= 2;

        // Find the position of the element greater than or equal to max_L using lower_bound
        itr = lower_bound(L, L + N, max_L);

        // Insert max_L before the found position and remove the last element
        memmove(itr + 1, itr, (N - (itr - L)) * sizeof(int));
        *itr = max_L;
        N--;
    }

    // Calculate the answer and print it
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }
    printf("%lld\n", ans);

    // Free the memory allocated for the vector
    free(L);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int lower_bound(int *arr, int *arr_end, int key) {
    int *itr = arr;
    while (itr < arr_end) {
        if (*itr >= key) {
            return itr - arr;
        }
        itr++;
    }
    return arr_end - arr;
}

