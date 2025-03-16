
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements (n) and the threshold (k) from input
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize an array to hold the input values
    int *bb = (int *)malloc(n * sizeof(int));

    // Read n integers into the bb array
    for (int i = 0; i < n; i++)
        scanf("%d", &bb[i]);

    // Initialize an array to hold the results and a counter for the results
    int *aa = (int *)malloc(n * sizeof(int));
    int m = 0;

    // Process the input array in reverse order
    for (int a = n - 1; a >= 0; a--) {
        int j = 0;
        // While there are still counts left for the current index in bb
        while (bb[a] > 0) {
            // Check if the current index in aa is valid
            if (aa[j] >= a + k)
                bb[a]--; // Decrease the count for bb[a]
            j++; // Move to the next index in aa
        }
        // Shift elements in aa to make space for the current index
        for (int j_ = m++; j_ > j; j_--)
            aa[j_] = aa[j_ - 1];
        aa[j] = a; // Place the current index in aa
    }

    // Output the results, incrementing by 1 for 1-based indexing
    for (int i = 0; i < n; i++)
        printf("%d ", aa[i] + 1);

    printf("\n"); // Print a newline at the end

    // Free the memory allocated for the arrays
    free(bb);
    free(aa);

    return 0;
}
