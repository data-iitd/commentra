#include <stdio.h>
#include <stdlib.h>

int getNextInt(FILE *fp) {
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    int n = getNextInt(fp);
    int *mm = (int *)malloc((n + 1) * sizeof(int));
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        mm[i] = getNextInt(fp);
        mm[i + 1] = getNextInt(fp);
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = 0; // Initialize dp[i][j] to 0
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    printf("%d\n", dp[1][n]);

    // Free allocated memory
    free(mm);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

// <END-OF-CODE>
