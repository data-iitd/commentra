#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

<<<<<<< HEAD
// Function to read the next integer from input.
int getNextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function to compute the minimum number of matrix multiplications.
int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the number of matrices.
    int n = getNextInt();

    // Initialize arrays for matrix dimensions and dynamic programming.
    int *mm = (int *)malloc((n + 1) * sizeof(int));
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0; // Initialize dp array
        }
    }

    // Read matrix dimensions into the mm array.
    for (int i = 0; i < n; i++) {
        mm[i] = getNextInt();
        mm[i + 1] = getNextInt();
    }

    // Use dynamic programming to compute the minimum number of multiplications.
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX; // Initialize to maximum value
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] > d) {
                    dp[i][j] = d;
=======
// Function to get the minimum number of matrix multiplications.
int matrixChainOrder(int p[], int n) {
    int dp[n+1][n+1];
    
    // Initialize the dp array.
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0; // Cost is zero when multiplying one matrix.
    }

    // l is chain length.
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX; // Set to maximum value initially.
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q; // Update the minimum cost.
>>>>>>> 98c87cb78a (data updated)
                }
            }
        }
    }
<<<<<<< HEAD

    // Print the result to the standard output.
    printf("%d\n", dp[1][n]);

    // Free allocated memory.
    free(mm);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

=======
    
    return dp[1][n]; // Return the minimum cost for multiplying matrices from 1 to n.
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    // Read the number of matrices.
    int n;
    fscanf(fp, "%d", &n);

    // Initialize array for matrix dimensions.
    int *mm = (int *)malloc((n + 1) * sizeof(int));

    // Read matrix dimensions.
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &mm[i]);
        fscanf(fp, "%d", &mm[i + 1]);
    }

    // Compute the minimum number of multiplications.
    int result = matrixChainOrder(mm, n);

    // Print the result.
    printf("%d\n", result);

    // Clean up and close the file if it was opened.
    if (fp != stdin) {
        fclose(fp);
    }
    free(mm);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
