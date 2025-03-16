#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t;
    
    // Read the number of cells (n) and the target cell (t) from input
    scanf("%d %d", &n, &t);
    
    // Read the list of jumps for each cell
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    // Initialize the current cell position
    int current_cell = 1; // Start from cell 1 (1-based index)

    // Loop until the current cell exceeds the target cell
    while (current_cell <= t) {
        // Move to the next cell based on the jump value from the current cell
        current_cell += s[current_cell - 1];
        
        // Check if the current cell is exactly the target cell
        if (current_cell == t) {
            printf("YES\n");  // Print "YES" if the target cell is reached
            free(s);          // Free allocated memory
            return 0;        // Exit the program
        }
    }

    // If the loop ends without reaching the target cell, print "NO"
    printf("NO\n");
    free(s); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
