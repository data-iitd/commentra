#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to read the next integer from input
int getNextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main(int argc, char *argv[]) {
    // Determine the input source based on command-line arguments
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the number of elements (n) and the number of restricted positions (m)
    int n = getNextInt();
    int m = getNextInt();

    // Create an array to store the restricted positions
    int *aa = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        int pos = getNextInt();
        if (pos <= n) {
            aa[pos] = 1;
        }
    }

    // Initialize the dynamic programming array
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    dp[0] = 1;

    // Fill the dynamic programming array based on restricted positions
    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa[i + ii]) {
                continue;
            }
            dp[i + ii] = (dp[i + ii] + dp[i]) % MOD;
        }
    }

    // Print the result
    printf("%lld\n", dp[n]);

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
