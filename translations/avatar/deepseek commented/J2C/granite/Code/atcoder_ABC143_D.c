

#include <stdio.h>
#include <stdlib.h>

int find(int *li, int from, int target, int size);

int main() {
    // Step 1: Read the number of elements N from the standard input
    int N;
    scanf("%d", &N);

    // Step 2: Read N integers from the standard input and add them to the list L
    int *L = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Step 3: Sort the list L in ascending order
    qsort(L, N, sizeof(int), cmpfunc);

    // Step 4: Initialize a counter to zero
    int count = 0;

    // Step 5: Use two nested loops to iterate through the list L, selecting pairs of elements (a, b) where a < b
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i];
            int b = L[j];

            // Step 6: For each pair (a, b), call the find method to determine the number of elements in the list L
            // that are greater than a + b and are located after the index j+1
            int res = find(L, j + 1, a + b, N);

            // Step 7: Add the result of the find method to the counter count
            count = count + res;
        }
    }

    // Step 8: After all pairs have been processed, print the value of count
    printf("%d\n", count);

    // Step 9: Free the memory allocated for the list L
    free(L);

    return 0;
}

// Step 9: The find method uses a binary search algorithm to efficiently find the number of elements in the list L
// that are greater than a + b and are located after the index from
int find(int *li, int from, int target, int size) {
    int low = from;
    int upp = size - 1;
    int mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;

    if (upp - low < 0) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }

    while (upp - low > 1) {
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
        mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    }

    return low - from + 1;
}

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

