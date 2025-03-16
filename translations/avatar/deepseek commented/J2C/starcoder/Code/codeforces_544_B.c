#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, count;
    scanf("%d %d", &n, &count);
    printIsland(n, count);
    return 0;
}

// Method to print the island pattern based on the given size and count of 'L' characters
void printIsland(int n, int count) {
    int a = (n + 1) / 2; // Calculating the number of 'L' characters in the first diagonal
    int b = n / 2; // Calculating the number of 'L' characters in the second diagonal
    int max = a * a + b * b; // Calculating the maximum possible number of 'L' characters

    // Checking if the requested count exceeds the maximum possible 'L' characters
    if (count > max) {
        printf("NO\n"); // Printing "NO" if count is too high
        return; // Returning from the method as further execution is unnecessary
    }

    printf("YES\n"); // Printing "YES" as the count is within the allowed range

    // Building the island grid
    for (int i = 0; i < n; i++) {
        char *row = (char *) malloc(n * sizeof(char)); // Creating a row of characters
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && count > 0) { // Checking if the position should be 'L'
                row[j] = 'L'; // Appending 'L' to the row
                count--; // Decrementing the count of 'L' characters
            } else {
                row[j] = 'S'; // Appending 'S' to the row
            }
        }
        printf("%s\n", row); // Printing the constructed row
        free(row); // Deallocating the row
    }
}

