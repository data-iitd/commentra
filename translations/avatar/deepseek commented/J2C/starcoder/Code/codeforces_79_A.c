#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, turn;
    scanf("%d %d", &x, &y);
    turn = 0;
    while (1) {
        if (turn % 2 == 0) {
            if (x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else if (y >= 22) {
                y -= 22;
            } else {
                printf("Hanako\n");
                return 0;
            }
        } else {
            if (y >= 22) {
                y -= 22;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else if (x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else {
                printf("Ciel\n");
                return 0;
            }
        }
        turn++;
    }
    return 0;
}

