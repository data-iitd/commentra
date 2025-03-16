
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initializing standard input and output file pointers
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // If input file and output file are provided as command line arguments
    if (argc > 1) {
        // Open the input file
        fp = fopen(argv[1], "r");

        // If output file is provided, create it
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    // Initialize a new scanner for reading input
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the number of elements in the array
    int n;
    fscanf(fp, "%d", &n);

    // Initialize a slice of length n to store the elements
    int *ll = (int *)malloc(n * sizeof(int));

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &ll[i]);
    }

    // Sort the slice in ascending order
    qsort(ll, n, sizeof(int), compare);

    // Initialize the answer variable to 0
    int ans = 0;

    // Iterate through all possible pairs of elements
    for (int i = 0; i < n - 2; i++) {
        // Iterate through all possible right pointers
        for (int j = i + 1; j < n - 1; j++) {
            // Initialize the left and right pointers for binary search
            int l = j + 1;
            int r = n;

            // Binary search to find the index of the element greater than the sum of the current pair
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                    continue;
                }
                r = m;
            }

            // Update the answer variable
            ans += l - (j + 1);
        }
    }

    // Write the answer to the output file
    fprintf(wfp, "%d\n", ans);

    // Flush the writer buffer
    fflush(wfp);

    // Free the memory allocated for the slice
    free(ll);

    // Close the input and output files
    fclose(fp);
    fclose(wfp);

    return 0;
}

int compare(const void *a, const void *b) {
    // Function to compare two integers
    return (*(int *)a - *(int *)b);
}

