#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MOVEMENTS 1000

int main() {
    char record_of_movements[MAX_MOVEMENTS];  // Array to store movements
    int x = 0, y = 0;  // Initialize the starting position (x, y) to (0, 0)
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};  // Define movements for L, R, U, D
    char directions[4] = {'L', 'R', 'U', 'D'};  // Corresponding direction characters
    bool visited[200][200] = {false};  // Array to keep track of visited positions
    bool bug = false;  // Set a flag bug to false

    // Take input for the movements of a character
    scanf("%s", record_of_movements);

    // Mark the starting position as visited
    visited[100][100] = true;  // Offset by 100 to handle negative indices

    for (int i = 0; record_of_movements[i] != '\0'; i++) {  // Iterate over each movement in the input
        int temp_x = x;  // Store the current x position in a temporary variable
        int temp_y = y;  // Store the current y position in a temporary variable

        // Update the x and y coordinates based on the direction
        if (record_of_movements[i] == 'L') {
            x += d_movement[0][0];
            y += d_movement[0][1];
        } else if (record_of_movements[i] == 'R') {
            x += d_movement[1][0];
            y += d_movement[1][1];
        } else if (record_of_movements[i] == 'U') {
            x += d_movement[2][0];
            y += d_movement[2][1];
        } else if (record_of_movements[i] == 'D') {
            x += d_movement[3][0];
            y += d_movement[3][1];
        }

        // Check if the new position has been visited before
        if (visited[x + 100][y + 100] == false) {
            // Check the surrounding positions
            for (int j = 0; j < 4; j++) {
                int new_x = x + d_movement[j][0];
                int new_y = y + d_movement[j][1];
                if ((new_x != temp_x || new_y != temp_y) && visited[new_x + 100][new_y + 100]) {
                    bug = true;  // Set the bug flag to true if a bug is detected
                    break;  // Break out of the loop if a bug is detected
                }
            }
        } else {
            bug = true;  // Set the bug flag to true if the new position has been visited before
        }

        if (bug) {  // Check if a bug was detected
            break;  // Break out of the loop if a bug was detected
        }

        visited[x + 100][y + 100] = true;  // Mark the new position as visited
    }

    if (bug) {  // Check if a bug was detected
        printf("BUG\n");  // Print 'BUG' if a bug was detected
    } else {
        printf("OK\n");  // Print 'OK' if no bug was detected
    }

    return 0;
}
