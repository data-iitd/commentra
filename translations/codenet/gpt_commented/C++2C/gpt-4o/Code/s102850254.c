#include <stdio.h>
#include <string.h>

// Global variables
int d; // Number of test cases
<<<<<<< HEAD
char map[105][107]; // 2D map representation
=======
char map[105][105]; // 2D map representation
>>>>>>> 98c87cb78a (data updated)
int n; // Size of the map

// Function to visit and modify the map based on certain conditions
void visit() {
    // Direction vectors for moving in 4 possible directions (up, right, down, left)
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int sum, flg = 0; // Initialize sum and flag for direction
    int x = 2, y = n; // Starting position on the map
    map[y][x] = ' '; // Mark the starting position as visited
    int ab[4] = {2, 2, 2, 2}; // Array to track the last three sums

    // Infinite loop to traverse the map
    while (1) {
        sum = 0; // Reset sum for the current direction
        while (1) {
            // Check if the next position is valid (not a wall and not already visited)
            if (map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' && map[y + dy[flg]][x + dx[flg]] != ' ') {
                flg++; // Change direction
                break; // Exit the inner loop
            }

            // Mark the current position as visited
            map[y + dy[flg]][x + dx[flg]] = ' ';
            // Move to the next position
            y = y + dy[flg];
            x = x + dx[flg];
            sum++; // Increment the sum of visited positions
        }
        // Reset direction if all 4 directions have been tried
        if (flg == 4) flg = 0;
        // Break the loop if no positions were visited in this direction
        if (sum == 0) break;
        // Update the history of sums
        ab[0] = ab[1];
        ab[1] = ab[2];
        ab[2] = sum;
        // Break if the last three sums are all 1 (indicating a dead end)
        if (ab[0] == 1 && ab[2] == 1 && ab[1] == 1) break;
    }
}

// Main function
int main() {
    // Read the number of test cases
    scanf("%d", &d);

    // Loop through each test case
    for (int l = 0; l < d; l++) {
        // Read the size of the map
        scanf("%d", &n);

        // Handle the case where the map size is 1
        if (n == 1) {
            printf("#\n"); // Output a single wall
            if (l != d - 1) printf("\n"); // Print a newline if not the last test case
            continue; // Skip to the next test case
        }

        // Initialize the map with walls and empty spaces
        for (int i = 0; i <= n + 1; i++) {
<<<<<<< HEAD
            memset(map[i], '#', sizeof(map[i])); // Fill the map with walls
            // Set the border of the map to empty spaces
            if (i == 0 || i == n + 1) {
                for (int j = 0; j <= n + 1; j++) {
                    map[i][j] = '.';
                }
            } else {
                map[i][0] = map[i][n + 1] = '.';
=======
            for (int j = 0; j <= n + 1; j++) {
                map[i][j] = '#'; // Fill the map with walls
                // Set the border of the map to empty spaces
                if (i == 0 || j == 0 || i == n + 1 || j == n + 1) map[i][j] = '.';
>>>>>>> 98c87cb78a (data updated)
            }
        }

        // Call the visit function to modify the map
        visit();

        // Output the modified map
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n + 1; j++) {
                printf("%c", map[i][j]); // Print each row of the map
            }
            printf("\n"); // Newline after each row
        }
        // Print a newline between test cases if not the last one
        if (l != d - 1) 
            printf("\n");
    }
    return 0; // Return success
}

// <END-OF-CODE>
