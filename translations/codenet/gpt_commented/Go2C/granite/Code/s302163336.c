
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, a, b, i, j, ans;
    int *h, *good;

    // Read the number of elements (n) and the number of comparisons (m)
    scanf("%d %d", &n, &m);

    // Create a slice to hold the heights and a slice to track which elements are "good"
    h = (int*)malloc(n * sizeof(int));
    good = (int*)malloc(n * sizeof(int));

    // Read the heights and initialize the good slice to true
    for (i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read height for each element
        good[i] = 1;        // Initially, all elements are considered "good"
    }

    // Process each comparison
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); // Read the first index (0-based) and the second index (0-based)

        // Compare the heights and update the good slice accordingly
        if (h[a - 1] > h[b - 1]) {
            good[b - 1] = 0; // If ai is taller, bi is not "good"
        } else if (h[a - 1] < h[b - 1]) {
            good[a - 1] = 0; // If bi is taller, ai is not "good"
        } else {
            // If heights are equal, mark both as not "good"
            good[a - 1] = 0;
            good[b - 1] = 0;
        }
    }

    // Count the number of "good" elements
    ans = 0;
    for (i = 0; i < n; i++) {
        ans += good[i]; // Increment count for each "good" element
    }

    // Print the result: the number of "good" elements
    printf("%d\n", ans);

    // Free the allocated memory
    free(h);
    free(good);

    return 0;
}
