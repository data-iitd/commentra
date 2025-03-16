#include <stdio.h>

int main() {
    int n;  // Number of lines in the input
    scanf("%d", &n);  // Read the number of lines
    char cake[n][n + 1];  // Initialize a 2D array to store each line (with an extra space for null terminator)
    int happiness = 0;  // Initialize happiness variable to zero
    int chocCount = 0;  // Initialize chocolate count variable to zero
    int nfat;  // Initialize nFAT variable

    // Read each line of the cake
    for (int i = 0; i < n; i++) {
        scanf("%s", cake[i]);  // Read a line and store it in the cake array
        chocCount = 0;  // Reset chocolate count for this line

        // Count 'C' in the current line
        for (int j = 0; cake[i][j] != '\0'; j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        // Calculate happiness based on chocolate count in the line
        if (chocCount > 1) {
            nfat = 1;  // Reset nFAT to 1
            for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT
                nfat *= k;
            }
            happiness += nfat / 2;  // Add happiness based on the nFAT value
        }
    }

    // Reset chocolate count for column calculation
    chocCount = 0;

    // Calculate happiness based on chocolate count in each column
    for (int j = 0; j < n; j++) {
        chocCount = 0;  // Reset chocolate count for this column
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        // Calculate happiness based on chocolate count in the column
        if (chocCount > 1) {
            nfat = 1;  // Reset nFAT to 1
            for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT
                nfat *= k;
            }
            happiness += nfat / 2;  // Add happiness based on the nFAT value
        }
    }

    printf("%d\n", happiness);  // Print the final happiness value as an integer.
    return 0;
}

// <END-OF-CODE>
