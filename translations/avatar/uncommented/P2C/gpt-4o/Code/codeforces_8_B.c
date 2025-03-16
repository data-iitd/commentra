#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char record_of_movements[100]; // Assuming a maximum length of 100 for the input
    int x = 0, y = 0;
    int d_movement[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} }; // L, R, U, D
    char visited[200][200] = {0}; // To track visited coordinates
    bool bug = false;

    // Read input
    scanf("%s", record_of_movements);
    
    // Mark the starting position as visited
    visited[100 + x][100 + y] = 1; // Offset by 100 to handle negative indices

    for (int i = 0; record_of_movements[i] != '\0'; i++) {
        char move = record_of_movements[i];
        int temp_x = x;
        int temp_y = y;

        // Update position based on the move
        if (move == 'L') {
            x += d_movement[0][0];
            y += d_movement[0][1];
        } else if (move == 'R') {
            x += d_movement[1][0];
            y += d_movement[1][1];
        } else if (move == 'U') {
            x += d_movement[2][0];
            y += d_movement[2][1];
        } else if (move == 'D') {
            x += d_movement[3][0];
            y += d_movement[3][1];
        }

        // Check for bugs
        if (visited[100 + x][100 + y] == 0) {
            for (int j = 0; j < 4; j++) {
                int new_x = x + d_movement[j][0];
                int new_y = y + d_movement[j][1];
                if ((new_x != temp_x || new_y != temp_y) && visited[100 + new_x][100 + new_y] == 1) {
                    bug = true;
                    break;
                }
            }
        } else {
            bug = true;
        }

        if (bug) {
            break;
        }

        // Mark the current position as visited
        visited[100 + x][100 + y] = 1;
    }

    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
