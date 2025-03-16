#include <stdio.h>
#include <stdbool.h>

#define NUM_FACES 6

// Dice represents a die with six faces
typedef struct {
    int nums[NUM_FACES]; // Array of integers representing the faces of the die
} Dice;

// rotate rotates the die in a specified direction a given number of times
void rotate(Dice *d, const char *direction, int times) {
    times %= 4; // Normalize the number of rotations to 4 or less
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

// roll rolls the die in a specified direction a given number of times
void roll(Dice *d, const char *direction, int times) {
    times %= 4; // Normalize the number of rolls to 4 or less
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

// printStatus prints the current status of the die in a formatted string
void printStatus(Dice *d) {
    printf("         ___\n");
    printf("    ____|_%3d_|_______\n", d->nums[0]);
    printf("    |_4_|_%3d_|_%3d_|_%3d_|\n", d->nums[3], d->nums[1], d->nums[2]);
<<<<<<< HEAD
    printf("        |_5_|\n\n");
=======
    printf("        |_5_|\n", d->nums[4]);
>>>>>>> 98c87cb78a (data updated)
}

// isEqual checks if two Dice objects have the same faces
bool isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < NUM_FACES; i++) {
        if (d1->nums[i] != d2->nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    Dice dice1, dice2;

    for (int i = 0; i < NUM_FACES; i++) {
        scanf("%d", &dice1.nums[i]);
    }
    for (int i = 0; i < NUM_FACES; i++) {
        scanf("%d", &dice2.nums[i]);
    }

    const char *directionOrder[] = {"N", "S", "W", "E"};
    const char *rollOrder[] = {"R", "L"};
    bool flag = false;

    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int d = 0; d < 4; d++) {
                for (int r = 0; r < 2; r++) {
                    Dice tmp = dice2; // Create a copy of dice2
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

// <END-OF-CODE>
