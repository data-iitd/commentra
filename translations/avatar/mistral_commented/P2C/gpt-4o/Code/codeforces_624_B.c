#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n); // Read an integer n from the standard input

    int *a = (int *)malloc(n * sizeof(int)); // Create a list a of size n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read n integers from the standard input
    }

    double pre = __DBL_MAX__; // Initialize pre to a large value
    int ans = 0; // Initialize ans to 0

    qsort(a, n, sizeof(int), compare); // Sort the list a in descending order

    for (int j = 0; j < n; j++) {
        ans += (pre - 1 < 0) ? 0 : (pre - 1 < a[j] ? pre - 1 : a[j]); // Calculate the value to add to ans
        pre = (pre - 1 < a[j]) ? pre - 1 : a[j]; // Update pre
    }

    printf("%d\n", ans); // Print the value of ans

    free(a); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
