
#include <stdio.h>
#include <stdlib.h>

// Function to get a new scanner from a file pointer
FILE *getScanner(FILE *fp) {
    return fp;
}

// Function to read the next string from the scanner
char *getNextString(FILE *scanner) {
    static char buffer[500001];
    fgets(buffer, 500001, scanner);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

// Function to read the next integer from the scanner
int getNextInt(FILE *scanner) {
    int i;
    fscanf(scanner, "%d", &i);
    return i;
}

// Main function to read input and process it
int main(int argc, char **argv) {
    // Open the standard input stream if no file is provided as an argument
    FILE *fp = stdin;
    if (argc > 1) {
        // Open the file provided as an argument and use it as the input stream
        fp = fopen(argv[1], "r");
    }

    // Initialize a new scanner from the input stream
    FILE *scanner = getScanner(fp);
    FILE *writer = stdout;

    // Read the number of test cases from the input
    int n = getNextInt(scanner);

    // Initialize a slice to store the prefix sum of squares of elements
    int mm[n+1];

    // Initialize a 2D slice to store the dynamic programming table
    int dp[n+1][n+1];

    // Read the elements and their prefix sum of squares from the input
    for (int i = 0; i < n; i++) {
        // Read the next integer as the current element
        mm[i+1] = getNextInt(scanner);
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
    fprintf(writer, "%d\n", dp[1][n]);

    // End of the code
    return 0;
}
