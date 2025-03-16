#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

#define MAX_SIZE 500001
=======
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

// Function to read the next integer from the input.
int getNextInt(FILE *fp) {
    int value;
    fscanf(fp, "%d", &value);
    return value;
}

int main(int argc, char *argv[]) {
<<<<<<< HEAD
    FILE *fp = stdin; // Default to standard input

    // Check if a filename is provided as a command-line argument.
=======
    // Determine the input source: standard input or a file specified as a command-line argument.
    FILE *fp = stdin;
>>>>>>> 98c87cb78a (data updated)
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open the file if a filename is provided.
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the number of elements.
    int n = getNextInt(fp);
<<<<<<< HEAD
    int mm[MAX_SIZE]; // Array to hold the input values.
    int dp[MAX_SIZE][MAX_SIZE] = {0}; // 2D array for dynamic programming.
=======
    int *mm = (int *)malloc((n + 1) * sizeof(int)); // Create a dynamic array to hold the input values.
    int **dp = (int **)malloc((n + 1) * sizeof(int *)); // Create a 2D array for dynamic programming.

    // Initialize the 2D array for dynamic programming.
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int)); // Each entry is initialized to zero by default.
        memset(dp[i], 0, (n + 1) * sizeof(int)); // Initialize the dp array to zero.
    }
>>>>>>> 98c87cb78a (data updated)

    // Read the input values into the mm array.
    for (int i = 0; i < n; i++) {
        mm[i] = getNextInt(fp); // Read the first value.
        mm[i + 1] = getNextInt(fp); // Read the second value.
    }

    // Perform dynamic programming to calculate the minimum cost.
    for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
        for (int i = 1; i <= n - l + 1; i++) { // i is the starting index of the subproblem.
            int j = i + l - 1; // j is the ending index of the subproblem.
            for (int k = i; k <= j - 1; k++) { // k is the partition point.
                // Calculate the cost of multiplying the matrices.
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                // Update the dp table with the minimum cost found.
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    // Output the minimum cost of multiplying the entire sequence of matrices.
    printf("%d\n", dp[1][n]);

<<<<<<< HEAD
=======
    // Free allocated memory.
    for (int i = 0; i <= n; i++) {
        free(dp[i]); // Free each row of the dp array.
    }
    free(dp); // Free the dp array.
    free(mm); // Free the mm array.

>>>>>>> 98c87cb78a (data updated)
    // Close the file if it was opened.
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

// <END-OF-CODE>
