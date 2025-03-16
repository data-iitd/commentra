#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read the size of the array
    int N;
    scanf("%d", &N);

    // Read the elements of the array
    int *A = (int *)malloc(N * sizeof(int));
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }

    // Sort the array
    qsort(A, N, sizeof(int), compare);

    // Find the minimum and maximum values in the array
    int min = A[0];
    int max = A[N - 1];

    // Count the occurrences of the minimum and maximum values
    long mins = 0;
    long maxs = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == min) mins++;
        if (A[i] == max) maxs++;
    }

    // Special case: if min == max
    if (min == max) {
        printf("%d %ld\n", (max - min), mins * (mins - 1) / 2);
    } else {
        // General case: if min != max
        printf("%d %ld\n", (max - min), mins * maxs);
    }

    // Free the allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
