#include <stdio.h>
#include <stdlib.h>

int find(int* li, int from, int target, int size) {
    int low = from;
    int upp = size - 1;
    int mid = (upp - low + 1) % 2 == 0 ? (low + upp) / 2 + 1 : (low + upp) / 2;

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
        mid = (upp - low + 1) % 2 == 0 ? (low + upp) / 2 + 1 : (low + upp) / 2;
    }

    return low - from + 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int* L = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Sort the list L in ascending order
    qsort(L, N, sizeof(int), (int (*)(const void*, const void*))compare);

    int count = 0;

    // Use two nested loops to iterate through the list L, selecting pairs of elements (a, b) where a < b
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i];
            int b = L[j];

            // For each pair (a, b), call the find method to determine the number of elements in the list L
            // that are greater than a + b and are located after the index j+1
            int res = find(L, j + 1, a + b, N);

            // Add the result of the find method to the counter count
            count = count + res;
        }
    }

    // After all pairs have been processed, print the value of count
    printf("%d\n", count);

    free(L);
    return 0;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
