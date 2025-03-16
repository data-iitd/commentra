#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 6
#define MAX_ROTATE 4
#define MAX_ROLL 4

typedef struct {
    int Nums[MAX_NUM];
} Dice;

void rotate(Dice *d, char direction, int times) {
    times %= MAX_ROTATE;
    switch (direction) {
        case 'W':
            for (int i = 0; i < times; i++) {
                d->Nums[0] = d->Nums[2];
                d->Nums[2] = d->Nums[5];
                d->Nums[5] = d->Nums[3];
                d->Nums[3] = d->Nums[0];
            }
            break;
        case 'E':
            for (int i = 0; i < times; i++) {
                d->Nums[0] = d->Nums[3];
                d->Nums[2] = d->Nums[5];
                d->Nums[5] = d->Nums[3];
                d->Nums[3] = d->Nums[0];
            }
            break;
        case 'N':
            for (int i = 0; i < times; i++) {
                d->Nums[0] = d->Nums[1];
                d->Nums[4] = d->Nums[5];
                d->Nums[5] = d->Nums[1];
                d->Nums[1] = d->Nums[0];
            }
            break;
        case 'S':
            for (int i = 0; i < times; i++) {
                d->Nums[5] = d->Nums[1];
                d->Nums[1] = d->Nums[0];
                d->Nums[0] = d->Nums[4];
                d->Nums[4] = d->Nums[5];
            }
            break;
    }
}

void roll(Dice *d, char direction, int times) {
    times %= MAX_ROLL;
    switch (direction) {
        case 'R':
            for (int i = 0; i < times; i++) {
                d->Nums[3] = d->Nums[1];
                d->Nums[1] = d->Nums[2];
                d->Nums[2] = d->Nums[4];
                d->Nums[4] = d->Nums[3];
            }
            break;
        case 'L':
            for (int i = 0; i < times; i++) {
                d->Nums[3] = d->Nums[4];
                d->Nums[1] = d->Nums[2];
                d->Nums[2] = d->Nums[4];
                d->Nums[4] = d->Nums[3];
            }
            break;
    }
}

void printStatus(Dice *d) {
    char status[100] =
        "  　　　 _ _ _ _\n"
        "   _ _ _|_%3d_|_ _ _ _ _ _\n"
        "  |_%3d_|_%3d_|_%3d_|_%3d_|\n"
        "       |_%3d_|\n";
    printf(status, d->Nums[0], d->Nums[3], d->Nums[1], d->Nums[2], d->Nums[4], d->Nums[5]);
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
        if (d1->Nums[i] != d2->Nums[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Dice dice1;
    Dice dice2;
    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%d", &dice1.Nums[i]);
    }
    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%d", &dice2.Nums[i]);
    }

    char directionOrder[4] = {'N', 'S', 'W', 'E'};
    char rollOrder[2] = {'R', 'L'};
    int flag = 0;

    CHECK:
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k < 4; k++) {
                    Dice tmp;
                    memcpy(tmp.Nums, dice2.Nums, sizeof(int) * MAX_NUM);
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[j], j);
                    if (isEqual(&tmp, &dice1)) {
                        flag = 1;
                        break CHECK;
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

