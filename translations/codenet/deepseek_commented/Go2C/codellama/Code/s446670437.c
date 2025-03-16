
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 6

typedef struct {
    int nums[MAX_NUM];
} Dice;

void rotate(Dice *d, char direction, int times) {
    times %= 4;
    switch (direction) {
        case 'W':
            for (int i = 0; i < times; i++) {
                d->nums[0] = d->nums[2];
                d->nums[2] = d->nums[5];
                d->nums[5] = d->nums[3];
                d->nums[3] = d->nums[0];
            }
            break;
        case 'E':
            for (int i = 0; i < times; i++) {
                d->nums[0] = d->nums[3];
                d->nums[2] = d->nums[5];
                d->nums[5] = d->nums[3];
                d->nums[3] = d->nums[0];
            }
            break;
        case 'N':
            for (int i = 0; i < times; i++) {
                d->nums[0] = d->nums[1];
                d->nums[4] = d->nums[5];
                d->nums[5] = d->nums[1];
                d->nums[1] = d->nums[0];
            }
            break;
        case 'S':
            for (int i = 0; i < times; i++) {
                d->nums[5] = d->nums[1];
                d->nums[1] = d->nums[0];
                d->nums[0] = d->nums[4];
                d->nums[4] = d->nums[5];
            }
            break;
    }
}

void roll(Dice *d, char direction, int times) {
    times %= 4;
    switch (direction) {
        case 'R':
            for (int i = 0; i < times; i++) {
                d->nums[3] = d->nums[1];
                d->nums[1] = d->nums[2];
                d->nums[2] = d->nums[4];
                d->nums[4] = d->nums[3];
            }
            break;
        case 'L':
            for (int i = 0; i < times; i++) {
                d->nums[3] = d->nums[4];
                d->nums[1] = d->nums[3];
                d->nums[2] = d->nums[1];
                d->nums[4] = d->nums[2];
            }
            break;
    }
}

void printStatus(Dice *d) {
    char status[100] =
        "     _ _ _ _\n"
        "  _ _ _|_%3d_|_ _ _ _ _ _\n"
        " |_%3d_|_%3d_|_%3d_|_%3d_|\n"
        "       |_%3d_|\n";
    printf(status, d->nums[0], d->nums[3], d->nums[1], d->nums[2], d->nums[4], d->nums[5]);
    printf("\n");
}

int getIndex(int *nums, int target) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (d1->nums[i] != d2->nums[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Dice dice1, dice2;
    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%d", &dice1.nums[i]);
    }
    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%d", &dice2.nums[i]);
    }

    char directionOrder[4] = {'N', 'S', 'W', 'E'};
    char rollOrder[2] = {'R', 'L'};
    int flag = 0;

    CHECK:
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 2; l++) {
                    Dice tmp;
                    memcpy(tmp.nums, dice2.nums, sizeof(int) * MAX_NUM);
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[l], j);
                    if (isEqual(&tmp, &dice1)) {
                        flag = 1;
                        break CHECK;
                    }
                }
            }
        }
    }
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

