#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get a new scanner from a file pointer
void getScanner(FILE *fp) {
    // No need to implement buffer in C as it's not needed for standard I/O
}

// Function to read the next string from the scanner
char* getNextString(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, fp) == -1) {
        return NULL;
    }
    return line;
}

// Function to read the next integer from the scanner
int getNextInt(FILE *fp) {
    char *line = getNextString(fp);
    return atoi(line);
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

    // Initialize a 2D array to store the dynamic programming table
    int n = getNextInt(fp);
    int mm[n+1];
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));

    // Read the elements and their prefix sum of squares from the input
    for (int i = 0; i < n; i++) {
        // Read the next integer as the current element
        mm[i+1] = getNextInt(fp);
        // Read the next integer as the next element's prefix sum of square
        mm[i+1] += mm[i] * mm[i];
    }

    // Process the dynamic programming table for all subarrays of given size
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i + l - 1;
            // Iterate through all subarrays of the current subarray
            for (int k = i; k <= j-1; k++) {
                // Calculate the sum of squares of elements in the current subarray
                int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
                // Update the dynamic programming table if a larger sum is found
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    // Print the result for the given input
    printf("%d\n", dp[1][n]);

    // Close the file if it was opened
    if (argc > 1) {
        fclose(fp);
    }

    return 0;
}
