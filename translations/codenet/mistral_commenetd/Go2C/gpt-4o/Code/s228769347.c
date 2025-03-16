// Include necessary headers
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Main function to solve the problem
int main(int argc, char *argv[]) {
    // Initialize file pointers for input and output
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // If input file and output file are provided as command line arguments
    if (argc > 1) {
        // Open the input file
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening input file");
            return EXIT_FAILURE;
        }

        // If output file is provided, create it
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
            if (wfp == NULL) {
                perror("Error opening output file");
                fclose(fp);
                return EXIT_FAILURE;
            }
        }
    }

    // Read the number of elements in the array
    int n;
    fscanf(fp, "%d", &n);

    // Initialize an array to store the elements
    int *ll = (int *)malloc(n * sizeof(int));
    if (ll == NULL) {
        perror("Memory allocation failed");
        fclose(fp);
        fclose(wfp);
        return EXIT_FAILURE;
    }

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &ll[i]);
    }

    // Sort the array in ascending order
    qsort(ll, n, sizeof(int), compare);

    // Initialize the answer variable to 0
    int ans = 0;

    // Iterate through all possible pairs of elements
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            // Initialize the left and right pointers for binary search
            int l = j + 1;
            int r = n;

            // Binary search to find the index of the element greater than the sum of the current pair
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            // Update the answer variable
            ans += l - (j + 1);
        }
    }

    // Write the answer to the output file
    fprintf(wfp, "%d\n", ans);

    // Free allocated memory
    free(ll);

    // Close the file pointers
    fclose(fp);
    fclose(wfp);

    return EXIT_SUCCESS;
}

// <END-OF-CODE>
