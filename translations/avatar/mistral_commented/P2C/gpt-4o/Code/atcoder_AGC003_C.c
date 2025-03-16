#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    // Ask the user for an integer `N` and store it in a variable called `N`

    int *A = (int *)malloc(N * sizeof(int));
    // Create a dynamic array `A` with `N` elements.

    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        A[i] = input * N + i;
        // Each element is the product of an integer input by the user and `N`,
        // plus an index `i` that goes from `0` to `N-1`.
    }

    qsort(A, N, sizeof(int), compare);
    // Sort the array `A` in ascending order.

    int cnt = 0;
    // Initialize a counter `cnt` to zero.

    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        // Calculate the remainder of `A[i]` divided by `N` and modulo 2.
        
        if (d % 2 != i % 2) {
            // Check if the remainder of `d` divided by 2 is different from the remainder of `i` divided by 2.
            // If they are different, increment the counter `cnt` by 1.
            cnt++;
        }
    }

    printf("%d\n", cnt / 2);
    // After the loop finishes, print the result of the counter `cnt` divided by 2.

    free(A);
    // Free the allocated memory for the array `A`.

    return 0;
}
