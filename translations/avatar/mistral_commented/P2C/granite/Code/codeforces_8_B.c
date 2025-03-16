
#include <stdio.h>
#include <string.h>

int main() {
    char record_of_movements[1000];
    scanf("%s", record_of_movements);
    int x = 0, y = 0;
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int d[1000][2] = {{0, 0}};
    int bug = 0;
    int i, j;

    for (i = 0; record_of_movements[i]!= '\0'; i++) {
        int temp_x = x;
        int temp_y = y;

        x += d_movement[record_of_movements[i] - 'L'][0];
        y += d_movement[record_of_movements[i] - 'L'][1];

        for (j = 0; j < 4; j++) {
            if ((x + d_movement[j][0]!= temp_x || y + d_movement[j][1]!= temp_y) && (x + d_movement[j][0] == d[0][0] && y + d_movement[j][1] == d[0][1])) {
                bug = 1;
                break;
            }
        }

        for (j = 0; j < 1000; j++) {
            if (x == d[j][0] && y == d[j][1]) {
                break;
            }
        }

        if (j == 1000) {
            d[j][0] = x;
            d[j][1] = y;
        }
    }

    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }

    return 0;
}
