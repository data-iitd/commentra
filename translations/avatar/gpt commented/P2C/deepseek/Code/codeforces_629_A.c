#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char cake[n][n];
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    // Read the cake representation
    for (int i = 0; i < n; i++) {
        scanf("%s", cake[i]);
    }

    // Process each line of cake input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        // If there are more than one chocolate, calculate the happiness contribution
        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }

        // Reset variables for the next line
        nfat = 1;
        chocCount = 0;
    }

    // Initialize a counter for vertical chocolate counting
    int posCount = 0;

    // Count chocolates in each column of the cake
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        // If there are more than one chocolate in the column, calculate the happiness contribution
        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }

        // Reset variables for the next column
        nfat = 1;
        chocCount = 0;
    }

    // Print the total happiness as an integer
    printf("%d\n", happiness);

    return 0;
}
