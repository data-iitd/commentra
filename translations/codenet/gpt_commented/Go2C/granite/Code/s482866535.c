
#include <stdio.h>
#include <stdlib.h>

// getScanner initializes a new scanner for reading input from the provided file pointer.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL);
    return fp;
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *scanner) {
    static char str[500001];
    fscanf(scanner, "%s", str);
    return str;
}

// getNextInt retrieves the next integer from the scanner.
int getNextInt(FILE *scanner) {
    int i;
    fscanf(scanner, "%d", &i);
    return i;
}

int main() {
    // Determine the input source: standard input or a file specified as a command-line argument.
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open the file if a filename is provided.
    }

    // Initialize the scanner for reading input and a writer for output.
    FILE *scanner = getScanner(fp);
    FILE *writer = stdout;

    // Read the number of elements.
    int n = getNextInt(scanner);
    int *mm = (int *)malloc(sizeof(int) * (n + 1)); // Create a slice to hold the input values.
    int **dp = (int **)malloc(sizeof(int *) * (n + 1)); // Create a 2D slice for dynamic programming.

    // Initialize the 2D slice for dynamic programming.
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (n + 1)); // Each entry is initialized to zero by default.
    }

    // Read the input values into the mm slice.
    for (int i = 0; i < n; i++) {
        mm[i] = getNextInt(scanner); // Read the first value.
        mm[i + 1] = getNextInt(scanner); // Read the second value.
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
    fprintf(writer, "%d\n", dp[1][n]);

    // Flush the writer to ensure all output is written.
    fflush(writer);

    // Free the memory allocated for the slices.
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(mm);

    return 0;
}
