
#include <stdio.h>
#include <string.h>

int main() {
    char record_of_movements[1000];
    fgets(record_of_movements, 1000, stdin);
    int x = 0, y = 0;
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    char d[1000][2];
    int bug = 0;
    int i;
    for (i = 0; i < strlen(record_of_movements); i++) {
        int temp_x = x;
        int temp_y = y;
        x += d_movement[record_of_movements[i] - 'A'][0];
        y += d_movement[record_of_movements[i] - 'A'][1];
        if (x == temp_x && y == temp_y) {
            continue;
        }
        int j;
        for (j = 0; j < i; j++) {
            if ((x + d_movement[record_of_movements[j] - 'A'][0] == d[j][0]) && (y + d_movement[record_of_movements[j] - 'A'][1] == d[j][1])) {
                bug = 1;
                break;
            }
        }
        if (bug) {
            break;
        }
        d[i][0] = x;
        d[i][1] = y;
    }
    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }
    return 0;
}
