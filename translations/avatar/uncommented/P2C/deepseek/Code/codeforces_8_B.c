#include <stdio.h>
#include <stdbool.h>

int main() {
    char record_of_movements[1000];
    int x = 0, y = 0;
    int d_movement[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    int d[1000][1000] = {0};
    bool bug = false;

    scanf("%s", record_of_movements);

    d[0][0] = 1; // Mark the starting point

    for (int i = 0; record_of_movements[i] != '\0'; i++) {
        char move = record_of_movements[i];
        int temp_x = x, temp_y = y;

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

        if (d[x][y] != 0) {
            bug = true;
            break;
        }

        for (int j = 0; j < 4; j++) {
            int new_x = x + d_movement[j][0];
            int new_y = y + d_movement[j][1];
            if ((new_x != temp_x || new_y != temp_y) && d[new_x][new_y] != 0) {
                bug = true;
                break;
            }
        }

        if (bug) {
            break;
        }

        d[x][y] = 1; // Mark the current position
    }

    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
