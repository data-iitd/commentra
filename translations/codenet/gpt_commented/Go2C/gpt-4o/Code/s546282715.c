#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to read the next integer from input.
int getNextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main(int argc, char *argv[]) {
    // Set the input source to standard input; if a file is provided as an argument, open that file.
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read the first two integers, n and m, from the input.
    int n = getNextInt();
    int m = getNextInt();

    // Initialize an array to store the blocked positions.
    int *blocked = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        int pos = getNextInt();
        blocked[pos] = 1; // Mark the position as blocked.
    }

    // Create a dynamic programming array to store the number of ways to reach each position.
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

    // Iterate through each position from 0 to n.
    for (int i = 0; i < n; i++) {
        // Check the next two positions (i+1 and i+2) to see if they can be reached.
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (blocked[i + ii]) {
                continue; // If blocked, skip to the next iteration.
            }
            // Update the number of ways to reach position i+ii based on the current position i.
            dp[i + ii] = (dp[i + ii] + dp[i]) % MOD;
        }
    }

    // Output the total number of ways to reach position n.
    printf("%lld\n", dp[n]);

    // Free allocated memory.
    free(blocked);
    free(dp);

    // Close the file if it was opened.
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

// <END-OF-CODE>
