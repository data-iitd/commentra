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
    // Step 1: Read the number of elements N from the standard input
    int N;
    scanf("%d", &N);

    // Step 2: Read N integers from the standard input and add them to the array L
    int *L = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Step 3: Sort the array L in ascending order
    qsort(L, N, sizeof(int), compare);

    // Step 4: Initialize a counter to zero
    int count = 0;

    // Step 5: Use two nested loops to iterate through the array L, selecting pairs of elements (a, b) where a < b
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i];
            int b = L[j];

            // Step 6: For each pair (a, b), call the find method to determine the number of elements in the array L
            // that are greater than a + b and are located after the index j+1
            int res = find(L, N, j + 1, a + b);

            // Step 7: Add the result of the find method to the counter count
            count += res;
        }
    }

    // Step 8: After all pairs have been processed, print the value of count
    printf("%d\n", count);

    // Free allocated memory
    free(L);

    return 0;
}

// <END-OF-CODE>
