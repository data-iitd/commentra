#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to read an integer from the input
int getNextInt(FILE *fp) {
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

// Main function
int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Check if file paths are provided as command-line arguments.
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    // Read the number of elements.
    int n = getNextInt(fp);
    int *ll = (int *)malloc(n * sizeof(int));

    // Read n integers into the array ll.
    for (int i = 0; i < n; i++) {
        ll[i] = getNextInt(fp);
    }

    // Sort the array ll.
    qsort(ll, n, sizeof(int), compare);

    // Initialize the answer variable.
    int ans = 0;

    // Iterate through possible triplets (i, j, m) where i < j < m.
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            // Add the number of valid m's to the answer.
            ans += l - (j + 1);
        }
    }

    // Print the final answer to the standard output.
    fprintf(wfp, "%d\n", ans);

    // Free allocated memory
    free(ll);

    // Close files if they were opened
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
