
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define a constant number for modulo operations
    int num = 998244353;

    // Initialize variables to read input from standard input
    char buf[1024];
    fgets(buf, 1024, stdin);
    int n = atoi(buf);

    // Create two arrays to store the two sets of integers
    int *ai = (int *)malloc(sizeof(int) * n);
    int *bi = (int *)malloc(sizeof(int) * n);

    // Read n pairs of integers from input
    for (int i = 0; i < n; i++) {
        fgets(buf, 1024, stdin);
        char *token = strtok(buf, " ");
        ai[i] = atoi(token);
        token = strtok(NULL, " ");
        bi[i] = atoi(token);
    }

    // Sort both arrays to prepare for median calculation
    qsort(ai, n, sizeof(int), cmpfunc);
    qsort(bi, n, sizeof(int), cmpfunc);

    // Check if the number of elements is odd
    if (n % 2 == 1) {
        // Calculate the result for odd n using the median values
        printf("%d\n", bi[n / 2] - ai[n / 2] + 1);
    } else {
        // Calculate the average of the two middle values for even n
        double b = (ai[n / 2] + ai[n / 2 - 1] + 0.0) / 2;
        double c = (bi[n / 2] + bi[n / 2 - 1] + 0.0) / 2;
        // Calculate the result for even n and print it
        printf("%d\n", (int)(2 * (c - b) + 1));
    }

    // Free the allocated memory
    free(ai);
    free(bi);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

