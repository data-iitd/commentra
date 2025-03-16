#include <stdio.h>
#include <stdlib.h>

// Function to read the next integer from the input
int getNextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function to read input and process it
int main(int argc, char *argv[]) {
    // Open the standard input stream if no file is provided as an argument
    FILE *fp = stdin;
    if (argc > 1) {
        // Open the file provided as an argument and use it as the input stream
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the number of test cases from the input
    int n = getNextInt();

    // Initialize an array to store the prefix sum of squares of elements
    int *mm = (int *)malloc((n + 1) * sizeof(int));
    mm[0] = 0;

    // Initialize a 2D array to store the dynamic programming table
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0; // Initialize the dp table
        }
    }

    // Read the elements and their prefix sum of squares from the input
    for (int i = 0; i < n; i++) {
        mm[i + 1] = getNextInt();
        mm[i + 1] += mm[i] * mm[i];
    }

    // Process the dynamic programming table for all subarrays of given size
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            // Iterate through all subarrays of the current subarray
            for (int k = i; k <= j - 1; k++) {
                // Calculate the sum of squares of elements in the current subarray
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                // Update the dynamic programming table if a larger sum is found
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    // Print the result for the given input
    printf("%d\n", dp[1][n]);

    // Free allocated memory
    free(mm);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    // End of the code
    return 0;
}
