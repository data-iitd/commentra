
#include <stdio.h>
#include <string.h>

int main() {
    // Read the input string representing movements
    char record_of_movements[1000];
    fgets(record_of_movements, sizeof(record_of_movements), stdin);

    // Initialize the starting coordinates (x, y) at (0, 0)
    int x = 0, y = 0;

    // Define the movement directions: Left (L), Right (R), Up (U), Down (D)
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    char d_steps[4] = {'L', 'R', 'U', 'D'};

    // Create a dictionary to track visited coordinates, starting with the initial position
    int d[1000][2] = {{0, 0}};
    int d_size = 1;

    // Initialize a flag to detect if a bug occurs
    int bug = 0;

    // Iterate through each movement in the input string
    for (int i = 0; record_of_movements[i]!= '\0'; i++) {
        // Store the current position before the move
        int temp_x = x, temp_y = y;

        // Update the coordinates based on the movement direction
        x += d_movement[record_of_movements[i] - '0'][0];
        y += d_movement[record_of_movements[i] - '0'][1];

        // Check if the new position has already been visited
        int found = 0;
        for (int j = 0; j < d_size; j++) {
            if (d[j][0] == x && d[j][1] == y) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // If not visited, check for potential bugs by looking at all movement directions
            for (int j = 0; j < 4; j++) {
                if ((x + d_movement[j][0]!= temp_x || y + d_movement[j][1]!= temp_y) &&
                    (x + d_movement[j][0]!= 0 || y + d_movement[j][1]!= 0)) {
                    for (int k = 0; k < d_size; k++) {
                        if (d[k][0] == x + d_movement[j][0] && d[k][1] == y + d_movement[j][1]) {
                            found = 1;
                            break;
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
        }

        if (found) {
            // If a bug is detected, set the flag and break the loop
            bug = 1;
            break;
        }

        // Mark the new position as visited
        d[d_size][0] = x;
        d[d_size][1] = y;
        d_size++;
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
