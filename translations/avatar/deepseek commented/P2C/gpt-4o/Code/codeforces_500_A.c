#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t;
    
    // Read the number of cells (n) and the target cell (t)
    scanf("%d %d", &n, &t);
    
    // Allocate memory for the list of cells
    int *s = (int *)malloc(n * sizeof(int));
    
    // Read the list of cells that can be jumped from each cell
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    // Initialize the current cell to 0
    int current_cell = 0;

    // Loop until the current cell exceeds the target cell
    while (current_cell < t) {
        // Update the current cell by adding the value of the cell it's currently on
        current_cell += s[current_cell];
        
        // Check if the current cell is the target cell
        if (current_cell == t) {
            // If yes, print "YES" and exit the program
            printf("YES\n");
            free(s);
            return 0;
        }
    }

    // If the loop finishes without finding the target cell, print "NO"
    printf("NO\n");
    
    // Free the allocated memory
    free(s);
    
    return 0;
}

// <END-OF-CODE>
