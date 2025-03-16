#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Define a constant number for modulo operations
    int num = 998244353;

    // Read the number of pairs (n) from input
    int n;
    scanf("%d", &n);

    // Create two arrays to store the two sets of integers
    int *ai = (int *)malloc(n * sizeof(int));
    int *bi = (int *)malloc(n * sizeof(int));

    // Read n pairs of integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ai[i], &bi[i]);
    }

    // Sort both arrays to prepare for median calculation
    qsort(ai, n, sizeof(int), compare);
    qsort(bi, n, sizeof(int), compare);

    // Check if the number of elements is odd
    if (n % 2 == 1) {
        // Calculate the result for odd n using the median values
        printf("%d\n", bi[n / 2] - ai[n / 2] + 1);
    } else {
        // Calculate the average of the two middle values for even n
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        // Calculate the result for even n and print it
        printf("%d\n", (int)(2 * (c - b) + 1));
    }

    // Free allocated memory
    free(ai);
    free(bi);

    return 0;
}
