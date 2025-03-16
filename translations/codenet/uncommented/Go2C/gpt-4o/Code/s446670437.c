#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int nums[6];
} Dice;

void rotate(Dice *d, const char *direction, int times) {
    times %= 4;
    for (int i = 0; i < times; i++) {
        if (direction[0] == 'W') {
            int temp = d->nums[0];
            d->nums[0] = d->nums[2];
            d->nums[2] = d->nums[5];
            d->nums[5] = d->nums[3];
            d->nums[3] = temp;
        } else if (direction[0] == 'E') {
            int temp = d->nums[0];
            d->nums[0] = d->nums[3];
            d->nums[3] = d->nums[5];
            d->nums[5] = d->nums[2];
            d->nums[2] = temp;
        } else if (direction[0] == 'N') {
            int temp = d->nums[0];
            d->nums[0] = d->nums[1];
            d->nums[1] = d->nums[5];
            d->nums[5] = d->nums[4];
            d->nums[4] = temp;
        } else if (direction[0] == 'S') {
            int temp = d->nums[5];
            d->nums[5] = d->nums[1];
            d->nums[1] = d->nums[0];
            d->nums[0] = d->nums[4];
            d->nums[4] = temp;
        }
    }
}

void roll(Dice *d, const char *direction, int times) {
    times %= 4;
    for (int i = 0; i < times; i++) {
        if (direction[0] == 'R') {
            int temp = d->nums[3];
            d->nums[3] = d->nums[1];
            d->nums[1] = d->nums[2];
            d->nums[2] = d->nums[4];
            d->nums[4] = temp;
        } else if (direction[0] == 'L') {
            int temp = d->nums[3];
            d->nums[3] = d->nums[4];
            d->nums[4] = d->nums[2];
            d->nums[2] = d->nums[1];
            d->nums[1] = temp;
        }
    }
}

void printStatus(Dice *d) {
    printf("         ___\n");
    printf("    ____|_%3d_|_______\n", d->nums[0]);
    printf("    |_4_|_%3d_|_%3d_|_%3d_|\n", d->nums[3], d->nums[1], d->nums[2]);
    printf("        |_5_|\n\n");
}

bool isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < 6; i++) {
        if (d1->nums[i] != d2->nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    Dice dice1, dice2;

    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice1.nums[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice2.nums[i]);
    }

    const char *directionOrder[] = {"N", "S", "W", "E"};
    const char *rollOrder[] = {"R", "L"};
    bool flag = false;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int d = 0; d < 4; d++) {
                for (int r = 0; r < 2; r++) {
                    Dice tmp = dice2;
                    rotate(&tmp, directionOrder[d], i);
                    roll(&tmp, rollOrder[r], j);
                    if (isEqual(&tmp, &dice1)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }

    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
