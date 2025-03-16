#include <stdio.h>

int main() {
    int n;  // Size of the cake
    scanf("%d", &n);  // Take the size of the cake as input
    char cake[n][n];  // Initialize a 2D array to store the rows of the cake
    int happiness = 0;  // Initialize the happiness score to 0
    int chocCount = 0;  // Initialize the chocolate count to 0
    int nfat = 1;  // Initialize nfat to 1 for calculating factorial

    // Loop through each row of the cake
    for (int i = 0; i < n; i++) {
        scanf("%s", cake[i]);  // Take each row as input
        for (int j = 0; j < n; j++) {  // Loop through each character in the row
            if (cake[i][j] == 'C') {  // If the character is a chocolate
                chocCount++;  // Increment the chocolate count
            }
        }
        if (chocCount > 1) {  // If there is more than one chocolate in the row
            // Calculate the factorial of chocCount and update happiness
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }
        nfat = 1;  // Reset nfat to 1
        chocCount = 0;  // Reset chocCount to 0
    }

    // Loop through each column of the cake
    for (int j = 0; j < n; j++) {
        chocCount = 0;  // Reset the chocolate count for each column
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {  // If the character is a chocolate
                chocCount++;  // Increment the chocolate count
            }
        }
        if (chocCount > 1) {  // If there is more than one chocolate in the column
            // Calculate the factorial of chocCount and update happiness
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }
        nfat = 1;  // Reset nfat to 1
        chocCount = 0;  // Reset chocCount to 0
    }

    printf("%d\n", happiness);  // Print the integer value of happiness
    return 0;
}

// <END-OF-CODE>
