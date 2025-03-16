#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Declare and initialize a constant integer
    const int num = 998244353;

    // Read the number of elements 'n' from the input
    int n;
    scanf("%d", &n);

    // Create arrays to store the pairs of integers
    int *ai = (int *)malloc(n * sizeof(int));
    int *bi = (int *)malloc(n * sizeof(int));

    // Read the pairs of integers from the input and store them in the arrays
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ai[i], &bi[i]);
    }

    // Sort both arrays
    qsort(ai, n, sizeof(int), compare);
    qsort(bi, n, sizeof(int), compare);

    // Check if 'n' is odd or even
    if (n % 2 == 1) {
        // If 'n' is odd, calculate the range
        printf("%d\n", bi[n / 2] - ai[n / 2] + 1);
    } else {
        // If 'n' is even, calculate the range
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        printf("%d\n", (int)(2 * (c - b) + 1));
    }

    // Free allocated memory
    free(ai);
    free(bi);

    return 0;
}

// <END-OF-CODE>
