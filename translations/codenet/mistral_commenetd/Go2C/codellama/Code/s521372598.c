
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 100000000

int main() {
    // Main function
    int n, i, j, b, ans;
    int *xs, *as;

    // Read the number of elements in the array
    scanf("%d", &n);

    // Initialize an array xs of size n
    xs = (int *)malloc(n * sizeof(int));

    // Read the array elements
    as = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    // Iterate through the array as and assign the value xs[i]
    for (i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    // Sort the array xs in ascending order
    qsort(xs, n, sizeof(int), compare);

    // Assign the middle element of the sorted array xs to variable b
    b = xs[n / 2];

    // Initialize variable ans with 0
    ans = 0;

    // Iterate through the array xs and calculate the absolute difference between each element and b
    for (i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }

    // Print the answer
    printf("%d\n", ans);

    // Free the memory allocated for the arrays
    free(xs);
    free(as);

    return 0;
}

int compare(const void *a, const void *b) {
    // Function to compare two integers
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    // Function to calculate the absolute difference of a number
    if (n < 0) {
        return -n;
    }
    return n;
}

