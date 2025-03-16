#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nums[6];
} Dice;

void rotate(Dice *d, char direction, int times) {
    times %= 4;
    int temp;
    switch (direction) {
        case 'W':
            for (int i = 0; i < times; i++) {
                temp = d->nums[0];
                d->nums[0] = d->nums[2];
                d->nums[2] = d->nums[5];
                d->nums[5] = d->nums[3];
                d->nums[3] = temp;
            }
            break;
        case 'E':
            for (int i = 0; i < times; i++) {
                temp = d->nums[0];
                d->nums[0] = d->nums[3];
                d->nums[3] = d->nums[5];
                d->nums[5] = d->nums[2];
                d->nums[2] = temp;
            }
            break;
        case 'N':
            for (int i = 0; i < times; i++) {
                temp = d->nums[0];
                d->nums[0] = d->nums[1];
                d->nums[1] = d->nums[5];
                d->nums[5] = d->nums[4];
                d->nums[4] = temp;
            }
            break;
        case 'S':
            for (int i = 0; i < times; i++) {
                temp = d->nums[5];
                d->nums[5] = d->nums[1];
                d->nums[1] = d->nums[0];
                d->nums[0] = d->nums[4];
                d->nums[4] = temp;
            }
            break;
    }
}

void roll(Dice *d, char direction, int times) {
    times %= 4;
    int temp;
    switch (direction) {
        case 'R':
            for (int i = 0; i < times; i++) {
                temp = d->nums[3];
                d->nums[3] = d->nums[1];
                d->nums[1] = d->nums[2];
                d->nums[2] = d->nums[4];
                d->nums[4] = temp;
            }
            break;
        case 'L':
            for (int i = 0; i < times; i++) {
                temp = d->nums[3];
                d->nums[3] = d->nums[4];
                d->nums[4] = d->nums[2];
                d->nums[2] = d->nums[1];
                d->nums[1] = temp;
            }
            break;
    }
}

void printStatus(Dice *d) {
    printf("        _ _ _ _\n");
    printf("    _ _ _|_%3d_|_ _ _ _ _ _\n", d->nums[0]);
    printf("   |_%3d_|_%3d_|_%3d_|_%3d_|\n", d->nums[3], d->nums[1], d->nums[2], d->nums[4]);
    printf("        |_%3d_|\n", d->nums[5]);
    printf("\n");
}

int getIndex(int nums[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < 6; i++) {
        if (d1->nums[i] != d2->nums[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Dice dice1, dice2;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice1.nums[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice2.nums[i]);
    }

    char directionOrder[] = {'N', 'S', 'W', 'E'};
    char rollOrder[] = {'R', 'L'};
    int flag = 0;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 2; l++) {
                    Dice tmp = dice2;
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[l], j);
                    if (isEqual(&dice1, &tmp)) {
                        flag = 1;
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

