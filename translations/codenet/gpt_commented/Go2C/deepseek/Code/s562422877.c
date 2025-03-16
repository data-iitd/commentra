#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read the number of elements N from input
    int N;
    scanf("%d", &N);

    // Initialize a array A to hold N integers
    int A[N];

    // Read N integers from input into the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Sort the array A in ascending order using qsort
    qsort(A, N, sizeof(int), compare);

    // Initialize a variable to hold the total difference sum
    int ans = 0;

    // Calculate the sum of differences between consecutive elements in the sorted array
    for (int i = 1; i < N; i++) {
        ans += A[i] - A[i-1];
    }

    // Output the total sum of differences
    printf("%d\n", ans);

    return 0;
}
