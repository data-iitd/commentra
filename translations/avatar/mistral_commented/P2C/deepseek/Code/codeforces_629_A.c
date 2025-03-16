#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  // Read the number of lines in the input
    char cake[n][n];  // Initialize a 2D array to store each line
    int happiness = 0;  // Initialize happiness variable to zero
    int chocCount = 0;  // Initialize chocolate count variable to zero
    int nfat = 1;  // Initialize nFAT variable to 1

    // Read each line and store it in the 2D array
    for (int i = 0; i < n; i++) {
        scanf("%s", cake[i]);
    }

    // Calculate happiness based on lines
    for (int i = 0; i < n; i++) {
        chocCount = 0;
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            nfat = 1;
            for (int i = chocCount; i > chocCount - 2; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
    }

    // Calculate happiness based on columns
    for (int j = 0; j < n; j++) {
        chocCount = 0;
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            nfat = 1;
            for (int i = chocCount; i > chocCount - 2; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
    }

    printf("%d\n", happiness);  // Print the final happiness value
    return 0;
}
