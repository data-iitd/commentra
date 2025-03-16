#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Initialize variables and read input
    int N;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Sort the array in ascending order
    qsort(A, N, sizeof(int), compare);

    // Calculate the answer
    int ans = 0;
    printf("Calculating the answer...\n");
    for (int i = 1; i < N; i++) {
        ans += A[i] - A[i - 1];
    }

    // Print the answer
    printf("The answer is: %d\n", ans);

    // Free allocated memory
    free(A);
    return 0;
}

// <END-OF-CODE>
