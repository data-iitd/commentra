#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

// Function to calculate the absolute value of an integer.
int absint(int a) {
    return (a < 0) ? -a : a;
}

int main(int argc, char *argv[]) {
    // Determine the input source: standard input or a file specified as a command-line argument.
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the number of elements from the input.
    int n;
    fscanf(fp, "%d", &n);

    // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
    int *aa = (int *)malloc((n + 2) * sizeof(int));
    int sum = 0;

    // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &aa[i + 1]);
        sum += absint(aa[i + 1] - aa[i]);
    }
    // Include the difference between the last element and the element before it.
    sum += absint(aa[n + 1] - aa[n]);

    // Calculate and print the result for each element.
    for (int i = 1; i <= n; i++) {
        // Calculate the new sum of absolute differences if the i-th element is removed.
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        printf("%d\n", ans); // Output the result for the current element.
    }

    // Free the allocated memory.
    free(aa);

    // Close the file if it was opened.
    if (fp != stdin) {
        fclose(fp);
    }

    return EXIT_SUCCESS;
}

// <END-OF-CODE>
