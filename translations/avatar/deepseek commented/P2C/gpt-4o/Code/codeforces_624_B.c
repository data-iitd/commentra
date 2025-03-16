#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    // Step 1: Reading the number of elements (n)
    int n;
    scanf("%d", &n);

    // Step 2: Reading the list of elements (a)
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Initializing variables
    int pre = __INT_MAX__;  // Initialize pre to a large value
    long long ans = 0;      // Initialize ans to 0

    // Step 4: Sorting the list in descending order
    qsort(a, n, sizeof(int), compare);

    // Step 5: Iterating through the list
    for (int j = 0; j < n; j++) {
        // Calculate the maximum value that can be added to ans
        ans += (pre - 1 < a[j]) ? (pre - 1) : (a[j] > 0 ? a[j] : 0);
        // Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
        pre = (pre - 1 < a[j]) ? (pre - 1) : (a[j] > 0 ? a[j] : 0);
    }

    // Step 6: Printing the result
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
