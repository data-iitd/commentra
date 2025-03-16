
#include <stdio.h>

typedef struct {
    int Nums[6];
} Dice;

void rotate(Dice *d, char direction, int times) {
    times %= 4;
    switch (direction) {
        case 'W':
            for (int i = 0; i < times; i++) {
                int tmp = d->Nums[0];
                d->Nums[0] = d->Nums[2];
                d->Nums[2] = d->Nums[5];
                d->Nums[5] = d->Nums[3];
                d->Nums[3] = tmp;
            }
            break;
        case 'E':
            for (int i = 0; i < times; i++) {
                int tmp = d->Nums[0];
                d->Nums[0] = d->Nums[3];
                d->Nums[3] = d->Nums[5];
                d->Nums[5] = d->Nums[2];
                d->Nums[2] = tmp;
            }
            break;
        case 'N':
            for (int i = 0; i < times; i++) {
                int tmp = d->Nums[0];
                d->Nums[0] = d->Nums[1];
                d->Nums[1] = d->Nums[5];
                d->Nums[5] = d->Nums[4];
                d->Nums[4] = tmp;
            }
            break;
        case 'S':
            for (int i = 0; i < times; i++) {
                int tmp = d->Nums[0];
                d->Nums[0] = d->Nums[4];
                d->Nums[4] = d->Nums[5];
                d->Nums[5] = d->Nums[1];
                d->Nums[1] = tmp;
            }
            break;
    }
}

void roll(Dice *d, char direction, int times) {
    times %= 4;
    switch (direction) {
        case 'R':
            for (int i = 0; i < times; i++) {
                int tmp = d->Nums[3];
                d->Nums[3] = d->Nums[1];
                d->Nums[1] = d->Nums[2];
                d->Nums[2] = d->Nums[4];
                d->Nums[4] = tmp;
            }
            break;
        case 'L':
            for (int i = 0; i < times; i++) {
                int tmp = d->Nums[3];
                d->Nums[3] = d->Nums[4];
                d->Nums[4] = d->Nums[2];
                d->Nums[2] = d->Nums[1];
                d->Nums[1] = tmp;
            }
            break;
    }
}

void printStatus(Dice *d) {
    printf("	　　　 _ _ _ _\n");
    printf("     _ _ _|_%3d_|_ _ _ _ _ _\n", d->Nums[0]);
    printf("    |_%3d_|_%3d_|_%3d_|_%3d_|%\n", d->Nums[3], d->Nums[1], d->Nums[2], d->Nums[4]);
    printf("  　       |_%3d_|%\n", d->Nums[5]);
}

int getIndex(int *nums, int target) {
    int index = -1;
    for (int i = 0; i < 6; i++) {
        if (target == nums[i]) {
            index = i;
            break;
        }
    }
    return index;
}

int isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < 6; i++) {
        if (d1->Nums[i]!= d2->Nums[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Dice dice1 = {0};
    Dice dice2 = {0};
    for (int i = 0; i < 6; i++) {
        int n;
        scanf("%d", &n);
        dice1.Nums[i] = n;
    }
    for (int i = 0; i < 6; i++) {
        int n;
        scanf("%d", &n);
        dice2.Nums[i] = n;
    }

    char directionOrder[] = {'N', 'S', 'W', 'E'};
    char rollOrder[] = {'R', 'L'};
    int flag = 0;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 2; l++) {
                    Dice tmp = {0};
                    for (int m = 0; m < 6; m++) {
                        tmp.Nums[m] = dice2.Nums[m];
                    }
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[l], j);
                    if (isEqual(&tmp, &dice1)) {
                        flag = 1;
                        goto END;
                    }
                }
            }
        }
    }
END:
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
