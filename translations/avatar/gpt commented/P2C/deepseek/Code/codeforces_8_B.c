#include <stdio.h>
#include <stdbool.h>

int main() {
    char record_of_movements[1000];
    int x = 0, y = 0;
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    bool d[2000][2000] = {false};
    bool bug = false;

    // Read the input string representing movements
    scanf("%s", record_of_movements);

    // Mark the initial position as visited
    d[1000][1000] = true;

    // Iterate through each movement in the input string
    for (int i = 0; record_of_movements[i] != '\0'; i++) {
        // Store the current position before the move
        int temp_x = x, temp_y = y;

        // Update the coordinates based on the movement direction
        switch (record_of_movements[i]) {
            case 'L': x += d_movement[0][0]; y += d_movement[0][1]; break;
            case 'R': x += d_movement[1][0]; y += d_movement[1][1]; break;
            case 'U': x += d_movement[2][0]; y += d_movement[2][1]; break;
            case 'D': x += d_movement[3][0]; y += d_movement[3][1]; break;
        }

        // Check if the new position has already been visited
        if (!d[x + 1000][y + 1000]) {
            // If not visited, check for potential bugs by looking at all movement directions
            for (int j = 0; j < 4; j++) {
                // Check if moving in any direction from the new position leads to a visited position
                if (x + d_movement[j][0] != temp_x || y + d_movement[j][1] != temp_y) {
                    if (d[x + d_movement[j][0] + 1000][y + d_movement[j][1] + 1000]) {
                        // If a bug is detected, set the flag and break the loop
                        bug = true;
                        break;
                    }
                }
            }
        } else {
            // If the new position was already visited, set the bug flag
            bug = true;
        }

        // If a bug has been detected, exit the loop
        if (bug) {
            break;
        }

        // Mark the new position as visited
        d[x + 1000][y + 1000] = true;
    }

    // After processing all movements, check if a bug was detected
    if (bug) {
        // Print 'BUG' if a bug was found
        printf("BUG\n");
    } else {
        // Print 'OK' if no bugs were found
        printf("OK\n");
    }

    return 0;
}
