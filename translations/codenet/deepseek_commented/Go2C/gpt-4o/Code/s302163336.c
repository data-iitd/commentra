#include <stdio.h>
#include <stdlib.h>

int main() {
<<<<<<< HEAD
    int n, m;
    scanf("%d", &n); // Read the number of elements
    scanf("%d", &m); // Read the number of comparisons
=======
    int n, m; // Number of elements and comparisons
    scanf("%d %d", &n, &m); // Read the number of elements and comparisons
>>>>>>> 98c87cb78a (data updated)

    int *h = (int *)malloc(n * sizeof(int)); // Allocate memory for heights
    int *good = (int *)malloc(n * sizeof(int)); // Allocate memory for good status

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read the height of each element
        good[i] = 1; // Assume all elements are initially good (1 for true)
    }

    for (int i = 0; i < m; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi); // Read the indices
        ai--; // Adjust for 0-based index
        bi--; // Adjust for 0-based index

        if (h[ai] > h[bi]) {
            good[bi] = 0; // Mark the second element as not good
        } else if (h[ai] < h[bi]) {
            good[ai] = 0; // Mark the first element as not good
        } else {
            good[ai] = 0; // Mark both elements as not good if heights are equal
            good[bi] = 0;
        }
    }

    int ans = 0; // Initialize the count of good elements
    for (int i = 0; i < n; i++) {
        if (good[i]) { // Count the elements that are still good
            ans++;
        }
    }

    printf("%d\n", ans); // Print the number of good elements

    free(h); // Free allocated memory
    free(good); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
