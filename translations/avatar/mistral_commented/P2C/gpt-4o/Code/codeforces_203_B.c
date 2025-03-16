#include <stdio.h>

#define MAX_N 100 // Assuming a maximum size for n

// Function to solve a single test case
void solve_case() {
    int n, m;
    // Read input: number of rows and columns
    scanf("%d %d", &n, &m);

    // Initialize a 2D array 'count' of size n x n with all elements as 0
    int count[MAX_N][MAX_N] = {0};

    // Variable to store the answer
    int ans = -1;

    // Iterate through each query
    for (int k = 0; k < m; k++) {
        // Read input: x and y for the current query
        int x, y;
        scanf("%d %d", &x, &y);

        // Adjust input for array indexing
        x -= 1;
        y -= 1;

        // Check if there is a group of 3x3 cells with count equal to 9
        int found = 0;
        for (int i = x - 2; i <= x; i++) {
            for (int j = y - 2; j <= y; j++) {
                // Check if the cell is within the grid boundaries
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    // Increment the count of the current cell
                    count[i][j]++;
                    // If the count becomes 9, then we have found the group
                    if (count[i][j] == 9) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found) break; // Break outer loop if found
        }

        // If a group of 3x3 cells with count equal to 9 is found, then update the answer
        if (found) {
            ans = k + 1;
            break;
        }
    }

    // Print the answer
    printf("%d\n", ans);
}

// Main function to call the solve_case function
int main() {
    solve_case();
    return 0;
}

// <END-OF-CODE>
