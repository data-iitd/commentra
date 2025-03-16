#include <stdio.h>

void printIsland(int n, int count) {
    int a = (n + 1) / 2; // Calculate the side length 'a' of the square grid of size 'n x n'
    int b = n / 2; // Calculate the square of the side length 'b' of the grid
    int max = a * a + b * b; // Calculate the maximum number of 'L' islands that can be placed in the grid

    // Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if (count > max) {
        printf("NO\n"); // If yes, print "NO" and return from the method
        return;
    }

    printf("YES\n"); // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    // Initialize a variable to store a row of the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If the cell is in the position where an 'L' island can be placed, print 'L' and decrement the count
            if ((i + j) % 2 == 0 && count > 0) {
                printf("L");
                count--;
            } else {
                // Otherwise, print 'S'
                printf("S");
            }
        }
        // Print a newline character to represent the end of the row of the grid
        printf("\n");
    }
}

int main() {
    int n, count;
    scanf("%d", &n); // Read the first integer 'n' from the input
    scanf("%d", &count); // Read the second integer 'count' from the input
    printIsland(n, count); // Call the printIsland function with the arguments 'n' and 'count'
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
