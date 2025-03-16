#include <stdio.h>

// Define a Dice struct with a Numbers array to store the numbers on the dice.
typedef struct {
    int nums[6];
} Dice;

// Function to rotate the dice in a given direction by a given number of times.
void rotate(Dice *d, char direction, int times) {
    times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
    int temp;
    for (int i = 0; i < times; i++) {
        switch (direction) {
            case 'W': // West direction rotation logic
                temp = d->nums[0];
                d->nums[0] = d->nums[2];
                d->nums[2] = d->nums[5];
                d->nums[5] = d->nums[3];
                d->nums[3] = temp;
                break;
            case 'E': // East direction rotation logic
                temp = d->nums[0];
                d->nums[0] = d->nums[3];
                d->nums[3] = d->nums[5];
                d->nums[5] = d->nums[2];
                d->nums[2] = temp;
                break;
            case 'N': // North direction rotation logic
                temp = d->nums[0];
                d->nums[0] = d->nums[1];
                d->nums[1] = d->nums[5];
                d->nums[5] = d->nums[4];
                d->nums[4] = temp;
                break;
            case 'S': // South direction rotation logic
                temp = d->nums[5];
                d->nums[5] = d->nums[1];
                d->nums[1] = d->nums[0];
                d->nums[0] = d->nums[4];
                d->nums[4] = temp;
                break;
        }
    }
}

// Function to roll the dice in a given direction by a given number of times.
void roll(Dice *d, char direction, int times) {
    times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
    int temp;
    for (int i = 0; i < times; i++) {
        switch (direction) {
            case 'R': // Right direction roll logic
                temp = d->nums[3];
                d->nums[3] = d->nums[1];
                d->nums[1] = d->nums[2];
                d->nums[2] = d->nums[4];
                d->nums[4] = temp;
                break;
            case 'L': // Left direction roll logic
                temp = d->nums[3];
                d->nums[3] = d->nums[4];
                d->nums[4] = d->nums[2];
                d->nums[2] = d->nums[1];
                d->nums[1] = temp;
                break;
        }
    }
}

// Function to print the current status of the dice.
void printStatus(Dice d) {
    printf("        _ _ _ _ \n");
    printf("     _ _ _|_%3d_|_ _ _ _ _ _ \n", d.nums[0]);
    printf("    |_%3d_|_%3d_|_%3d_|_%3d_| \n", d.nums[3], d.nums[1], d.nums[2], d.nums[4]);
    printf("        |_%3d| \n", d.nums[5]);
    printf("\n");
}

// Function to get the index of a target number in a given array.
int getIndex(int nums[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to check if two dice have the same numbers.
int isEqual(Dice d1, Dice d2) {
    for (int i = 0; i < 6; i++) {
        if (d1.nums[i] != d2.nums[i]) {
            return 0;
        }
    }
    return 1;
}

// Main function to read user input and check if two dice are the same after certain rotations and rolls.
int main() {
    Dice dice1;
    Dice dice2;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice1.nums[i]);
    }
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice2.nums[i]);
    }

    char directionOrder[4] = {'N', 'S', 'W', 'E'}; // Order of directions to rotate
    char rollOrder[2] = {'R', 'L'};             // Order of rolls
    int flag = 0;

    // Check all possible combinations of rotations and rolls to find if the dice are the same.
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 2; l++) {
                    Dice tmp = dice2;
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[l], j);
                    if (isEqual(dice1, tmp)) {
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
