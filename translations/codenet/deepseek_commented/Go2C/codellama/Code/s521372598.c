#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 100000000

int main() {
    int n;
    int *as;
    int *xs;
    int b;
    int ans;
    int i;

    // Read the number of elements in the array
    scanf("%d", &n);

    // Allocate memory for the array
    as = (int *)malloc(n * sizeof(int));

    // Read the array
    for (i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    // Allocate memory for the sorted array
    xs = (int *)malloc(n * sizeof(int));

    // Create the sorted array
    for (i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }
    qsort(xs, n, sizeof(int), compare);

    // Choose the median as the value of b
    b = xs[n / 2];

    // Calculate the sum of absolute differences between each element in xs and b
    ans = 0;
    for (i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }

    // Print the result
    printf("%d\n", ans);

    // Free the memory
    free(as);
    free(xs);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

