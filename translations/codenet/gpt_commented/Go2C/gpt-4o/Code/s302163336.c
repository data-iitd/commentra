#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
<<<<<<< HEAD
    
=======

>>>>>>> 98c87cb78a (data updated)
    // Read the number of elements (n) and the number of comparisons (m)
    scanf("%d %d", &n, &m);

    // Create an array to hold the heights and an array to track which elements are "good"
    int *h = (int *)malloc(n * sizeof(int));
    int *good = (int *)malloc(n * sizeof(int));

<<<<<<< HEAD
    // Read the heights and initialize the good array to true (1)
=======
    // Initialize the good array to true (1)
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]); // Read height for each element
        good[i] = 1;        // Initially, all elements are considered "good"
    }

    // Process each comparison
    for (int i = 0; i < m; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi);
        ai--; // Convert to 0-based index
        bi--; // Convert to 0-based index

        // Compare the heights and update the good array accordingly
        if (h[ai] > h[bi]) {
            good[bi] = 0; // If ai is taller, bi is not "good"
        } else if (h[ai] < h[bi]) {
            good[ai] = 0; // If bi is taller, ai is not "good"
        } else {
            // If heights are equal, mark both as not "good"
            good[ai] = 0;
            good[bi] = 0;
        }
    }

    // Count the number of "good" elements
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++; // Increment count for each "good" element
        }
    }

    // Print the result: the number of "good" elements
    printf("%d\n", ans);

    // Free allocated memory
    free(h);
    free(good);

    return 0;
}

// <END-OF-CODE>
