#include <stdio.h>
#include <stdlib.h>

// Function to compare two elements for qsort
int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

int main() {
    int N;
    scanf("%d", &N);

    int *elements = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &elements[i]);
    }

    // Create an array of indices
    int *indices = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        indices[i] = i + 1;
    }

    // Sort the elements array and keep track of the original indices
    qsort(elements, N, sizeof(int), compare);

    // Print the indices in the required format
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", indices[i]);
    }
    printf("%d\n", indices[N - 1]);

    // Free allocated memory
    free(elements);
    free(indices);

    return 0;
}
