#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to read the next integer from the input
int getNextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int main(int argc, char *argv[]) {
    // Open the standard input file if the command line argument is provided
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the first two integers from the input
    int n = getNextInt();
    int m = getNextInt();

    // Initialize an associative array to store the elements
    int *aa = (int *)calloc(n + 1, sizeof(int));
    // Read m elements and store them in the associative array
    for (int i = 0; i < m; i++) {
        int value = getNextInt();
        if (value <= n) {
            aa[value] = 1;
        }
    }

    // Initialize a dynamic programming array
    int *dp = (int *)calloc(n + 1, sizeof(int));
    // Initialize the first element of the array
    dp[0] = 1;

    // Iterate through the array from index 0 to n-1
    for (int i = 0; i < n; i++) {
        // Iterate through the prefix sum from i to i+2
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            // Skip if the current index is already present in the associative array
            if (aa[i + ii]) {
                continue;
            }
            // Calculate the dynamic programming value for the current index
            dp[i + ii] = (dp[i + ii] + dp[i]) % MOD;
        }
    }

    // Print the final answer
    printf("%d\n", dp[n]);

    // Free allocated memory
    free(aa);
    free(dp);

    // Close the file if it was opened
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

// <END-OF-CODE>
