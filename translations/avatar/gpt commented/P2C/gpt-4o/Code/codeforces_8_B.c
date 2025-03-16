#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVEMENTS 1000
#define MAX_VISITED 10000

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int visited;
} Visited;

Visited visited_positions[MAX_VISITED];
int visited_count = 0;

int is_visited(int x, int y) {
    for (int i = 0; i < visited_count; i++) {
        if (visited_positions[i].pos.x == x && visited_positions[i].pos.y == y) {
            return 1; // Position is visited
        }
    }
    return 0; // Position is not visited
}

void mark_visited(int x, int y) {
    visited_positions[visited_count].pos.x = x;
    visited_positions[visited_count].pos.y = y;
    visited_count++;
}

int main() {
    char record_of_movements[MAX_MOVEMENTS];
    scanf("%s", record_of_movements);

    int x = 0, y = 0;
    int bug = 0;

    // Define movement directions: Left (L), Right (R), Up (U), Down (D)
    int d_movement[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    char directions[4] = { 'L', 'R', 'U', 'D' };

    // Mark the starting position as visited
    mark_visited(x, y);

    // Iterate through each movement in the input string
    for (int i = 0; record_of_movements[i] != '\0'; i++) {
        Position temp = { x, y };

        // Update the coordinates based on the movement direction
        switch (record_of_movements[i]) {
            case 'L': x += d_movement[0][0]; y += d_movement[0][1]; break;
            case 'R': x += d_movement[1][0]; y += d_movement[1][1]; break;
            case 'U': x += d_movement[2][0]; y += d_movement[2][1]; break;
            case 'D': x += d_movement[3][0]; y += d_movement[3][1]; break;
        }

        // Check if the new position has already been visited
        if (!is_visited(x, y)) {
            // If not visited, check for potential bugs
            for (int j = 0; j < 4; j++) {
                int new_x = x + d_movement[j][0];
                int new_y = y + d_movement[j][1];
                if (new_x != temp.x || new_y != temp.y) {
                    if (is_visited(new_x, new_y)) {
                        bug = 1; // Bug detected
                        break;
                    }
                }
            }
        } else {
            // If the new position was already visited, set the bug flag
            bug = 1;
        }

        // If a bug has been detected, exit the loop
        if (bug) {
            break;
        }

        // Mark the new position as visited
        mark_visited(x, y);
    }

    // After processing all movements, check if a bug was detected
    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
