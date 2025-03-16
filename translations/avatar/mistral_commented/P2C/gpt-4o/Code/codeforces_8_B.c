#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVEMENTS 1000
#define MAX_POSITIONS 1000

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int visited;
} PositionRecord;

int main() {
    char record_of_movements[MAX_MOVEMENTS];
    int x = 0, y = 0; // Initialize the starting position of the bug
    PositionRecord visited_positions[MAX_POSITIONS];
    int visited_count = 0;
    int bug = 0; // Initialize a boolean variable to check if the bug is trapped

    // Define the direction of movement
    int d_movement[4][2] = {
        {0, -1}, // L
        {0, 1},  // R
        {1, 0},  // U
        {-1, 0}  // D
    };

    // Read the input movements
    scanf("%s", record_of_movements);

    // Iterate through each movement in the record
    for (int i = 0; record_of_movements[i] != '\0'; i++) {
        // Save the current position of the bug
        Position temp = {x, y};

        // Move the bug based on the given direction
        switch (record_of_movements[i]) {
            case 'L':
                x += d_movement[0][0];
                y += d_movement[0][1];
                break;
            case 'R':
                x += d_movement[1][0];
                y += d_movement[1][1];
                break;
            case 'U':
                x += d_movement[2][0];
                y += d_movement[2][1];
                break;
            case 'D':
                x += d_movement[3][0];
                y += d_movement[3][1];
                break;
        }

        // Check if the new position is already visited
        int already_visited = 0;
        for (int j = 0; j < visited_count; j++) {
            if (visited_positions[j].pos.x == x && visited_positions[j].pos.y == y) {
                already_visited = 1;
                break;
            }
        }

        if (!already_visited) {
            // If not visited, add to the visited positions
            visited_positions[visited_count].pos.x = x;
            visited_positions[visited_count].pos.y = y;
            visited_positions[visited_count].visited = 1;
            visited_count++;
        } else {
            // If visited, check for loops
            for (int j = 0; j < 4; j++) {
                int new_x = x + d_movement[j][0];
                int new_y = y + d_movement[j][1];
                for (int k = 0; k < visited_count; k++) {
                    if (visited_positions[k].pos.x == new_x && visited_positions[k].pos.y == new_y && 
                        !(new_x == temp.x && new_y == temp.y)) {
                        // If a loop is found, set the bug is trapped flag
                        bug = 1;
                        break;
                    }
                }
                if (bug) break;
            }
        }
    }

    // Check if the bug is trapped
    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
