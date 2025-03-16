#include <stdio.h>
#include <stdlib.h>

void solve(int n, int k) {
    // Allocate memory for the array to hold the input numbers
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Read n integers from input and store them in the array
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // Sort the array in ascending order
    qsort(a, n, sizeof(int), (int (*)(const void *, const void *))compare);

    // Initialize a variable to hold the sum of the smallest k elements
    int ans = 0;

    // Sum the first k elements of the sorted array
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }

    // Output the result (sum of the smallest k elements)
    printf("%d\n", ans);

    // Free the allocated memory
    free(a);
}

// Comparison function for qsort
int compare(const int *a, const int *b) {
    return (*a - *b);
}

int main() {
    int n, k;

    // Read the number of elements (n) and the number of smallest elements to sum (k)
    scanf("%d %d", &n, &k);

    // Call the solve function to process the input and produce output
    solve(n, k);

    return 0;
}

// <END-OF-CODE>
