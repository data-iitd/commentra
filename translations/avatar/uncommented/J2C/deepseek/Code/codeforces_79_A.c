#include <stdio.h>
#include <stdbool.h>

bool canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) {
    if (xNeeded > xAvailable) return false;
    if (yNeeded > yAvailable) return false;
    return true;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int turn = 0;
    while (true) {
        if (turn % 2 == 0) {
            if (canTake(2, x, 2, y)) {
                x -= 2;
                y -= 2;
            } else if (canTake(1, x, 12, y)) {
                x -= 1;
                y -= 12;
            } else if (canTake(0, x, 22, y)) {
                y -= 22;
            } else {
                printf("Hanako\n");
                return 0;
            }
        } else {
            if (canTake(0, x, 22, y)) {
                y -= 22;
            } else if (canTake(1, x, 12, y)) {
                x -= 1;
                y -= 12;
            } else if (canTake(2, x, 2, y)) {
                x -= 2;
                y -= 2;
            } else {
                printf("Ciel\n");
                return 0;
            }
        }
        turn++;
    }
}
