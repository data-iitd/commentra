#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the list of integers
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the previous value to infinity
    int pre = __INT_MAX__;

    // Initialize the answer variable to accumulate the result
    long long ans = 0;

    // Sort the list in descending order
    qsort(a, n, sizeof(int), compare);

    // Iterate through the sorted list
    for (int j = 0; j < n; j++) {
        // Calculate the current contribution to the answer
        ans += (pre - 1 < a[j]) ? (pre - 1) : a[j];
        if (ans < 0) ans = 0; // Ensure non-negative contribution

        // Update the previous value for the next iteration
        pre = (pre - 1 < a[j]) ? (pre - 1) : a[j];
        if (pre < 0) pre = 0; // Ensure non-negative previous value
    }

    // Print the final accumulated answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
