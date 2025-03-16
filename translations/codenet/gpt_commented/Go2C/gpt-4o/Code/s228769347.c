#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
<<<<<<< HEAD
    return (*(int *)a - *(int *)b);
=======
    return (*(int *)a - *(int *)b;
>>>>>>> 98c87cb78a (data updated)
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin; // Default input is standard input.
    FILE *wfp = stdout; // Default output is standard output.

    // Check for command-line arguments to read from a file and write to a file.
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open the input file if provided.
        if (argc > 2) {
            wfp = fopen(argv[2], "w"); // Create the output file if provided.
        }
    }

    int n;
    fscanf(fp, "%d", &n); // Read the number of integers.
    int *ll = malloc(n * sizeof(int)); // Create a dynamic array to hold the integers.

    // Read n integers from the input.
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &ll[i]); // Populate the array with integers.
    }

    qsort(ll, n, sizeof(int), compare); // Sort the array of integers.

    int ans = 0; // Initialize the answer counter.
    // Iterate through pairs of integers to find valid triplets.
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1; // Start searching for the third element after the second element.
            int r = n; // Set the right boundary for binary search.
            // Perform binary search to find the count of valid third elements.
            while (l < r) {
                int m = (l + r) / 2; // Calculate the middle index.
                if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element.
                    l = m + 1; // Move the left boundary up.
                } else {
                    r = m; // Move the right boundary down.
                }
            }
            // Count the number of valid third elements.
            ans += l - (j + 1); // Update the answer with the count of valid triplets.
        }
    }
    fprintf(wfp, "%d\n", ans); // Print the result to the output.

    free(ll); // Free the allocated memory.
    if (fp != stdin) fclose(fp); // Close the input file if it was opened.
    if (wfp != stdout) fclose(wfp); // Close the output file if it was created.

<<<<<<< HEAD
    return 0; // Return success.
=======
    return 0;
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
