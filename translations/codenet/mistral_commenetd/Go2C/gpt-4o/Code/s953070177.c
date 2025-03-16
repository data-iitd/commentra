#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the absolute value of an integer
int absint(int a) {
    return a < 0 ? -a : a;
}

int main(int argc, char *argv[]) {
    // Open the standard input or a file if provided as an argument
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the first integer from the input
    int n;
    fscanf(fp, "%d", &n);

    // Initialize an array 'aa' of size 'n+2'
    int *aa = (int *)malloc((n + 2) * sizeof(int));
    if (aa == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    // Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
    int sum = 0;

    // Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &aa[i + 1]);
        sum += absint(aa[i + 1] - aa[i]);
    }
    // Calculate the absolute difference between the last two elements and add it to the sum
    sum += absint(aa[n + 1] - aa[n]);

    // Iterate through the array 'aa' and print the answer for each subarray
    for (int i = 1; i < n + 1; i++) {
        // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        printf("%d\n", ans);
    }

    // Free the allocated memory
    free(aa);

    // Close the file if it was opened
    if (fp != stdin) {
        fclose(fp);
    }

    return EXIT_SUCCESS;
}

// <END-OF-CODE>
