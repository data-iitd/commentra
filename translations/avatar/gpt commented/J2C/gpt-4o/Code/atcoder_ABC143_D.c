#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int find(int *arr, int size, int from, int target) {
    int low = from;
    int upp = size - 1;

    if (upp < low) {
        return 0;
    } else if (arr[from] >= target) {
        return 0;
    } else if (arr[upp] < target) {
        return upp - low + 1;
    }

    while (upp - low > 1) {
        int mid = (low + upp) / 2;
        if (arr[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
    }

    return low - from + 1;
}

int main() {
    int N;
    // Read the number of integers to be processed
    scanf("%d", &N);

    // Initialize an array to store the integers
    int *L = (int *)malloc(N * sizeof(int));

    // Read N integers from input and add them to the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Sort the array of integers in ascending order
    qsort(L, N, sizeof(int), compare);

    // Initialize a counter to keep track of valid pairs
    int count = 0;

    // Iterate through each pair of integers in the sorted array
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Get the current pair of integers
            int a = L[i];
            int b = L[j];

            // Find the number of integers that can form a valid triplet with a and b
            int res = find(L, N, j + 1, a + b);

            // Increment the count by the number of valid triplets found
            count += res;
        }
    }

    // Output the total count of valid triplets
    printf("%d\n", count);

    // Free the allocated memory
    free(L);

    return 0;
}

// <END-OF-CODE>
