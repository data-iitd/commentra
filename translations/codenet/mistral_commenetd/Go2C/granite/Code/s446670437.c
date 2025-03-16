
#include <stdio.h>
#include <stdlib.h>

// Define a Dice struct with a Numbers array to store the numbers on the dice.
typedef struct {
    int Numbers[6];
} Dice;

// Function to rotate the dice in a given direction by a given number of times.
void rotate(Dice *dice, char direction, int times) {
    times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
    switch (direction) {
        case 'W': // West direction rotation logic
            for (int i = 0; i < times; i++) {
                int temp = dice->Numbers[0];
                dice->Numbers[0] = dice->Numbers[2];
                dice->Numbers[2] = dice->Numbers[5];
                dice->Numbers[5] = dice->Numbers[3];
                dice->Numbers[3] = temp;
            }
            break;
        case 'E': // East direction rotation logic
            for (int i = 0; i < times; i++) {
                int temp = dice->Numbers[0];
                dice->Numbers[0] = dice->Numbers[3];
                dice->Numbers[3] = dice->Numbers[5];
                dice->Numbers[5] = dice->Numbers[2];
                dice->Numbers[2] = temp;
            }
            break;
        case 'N': // North direction rotation logic
            for (int i = 0; i < times; i++) {
                int temp = dice->Numbers[0];
                dice->Numbers[0] = dice->Numbers[1];
                dice->Numbers[1] = dice->Numbers[5];
                dice->Numbers[5] = dice->Numbers[4];
                dice->Numbers[4] = temp;
            }
            break;
        case 'S': // South direction rotation logic
            for (int i = 0; i < times; i++) {
                int temp = dice->Numbers[0];
                dice->Numbers[0] = dice->Numbers[4];
                dice->Numbers[4] = dice->Numbers[5];
                dice->Numbers[5] = dice->Numbers[1];
                dice->Numbers[1] = temp;
            }
            break;
    }
}

// Function to roll the dice in a given direction by a given number of times.
void roll(Dice *dice, char direction, int times) {
    times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
    switch (direction) {
        case 'R': // Right direction roll logic
            for (int i = 0; i < times; i++) {
                int temp = dice->Numbers[3];
                dice->Numbers[3] = dice->Numbers[1];
                dice->Numbers[1] = dice->Numbers[2];
                dice->Numbers[2] = dice->Numbers[4];
                dice->Numbers[4] = temp;
            }
            break;
        case 'L': // Left direction roll logic
            for (int i = 0; i < times; i++) {
                int temp = dice->Numbers[3];
                dice->Numbers[3] = dice->Numbers[4];
                dice->Numbers[4] = dice->Numbers[2];
                dice->Numbers[2] = dice->Numbers[1];
                dice->Numbers[1] = temp;
            }
            break;
    }
}

// Function to print the current status of the dice.
void printStatus(Dice dice) {
    printf(
        "	　　　 _ _ _ _\n"
        "     _ _ _|_%3d_|_ _ _ _ _ _\n"
        "    |_%3d_|_%3d_|_%3d_|_%3d_|\n"
        " 　       |_%3d_|\n",
        dice.Numbers[0], dice.Numbers[3], dice.Numbers[1], dice.Numbers[2], dice.Numbers[4], dice.Numbers[5]
    );
}

// Function to get the index of a target number in a given array.
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

// Function to check if two dice have the same numbers.
int isEqual(Dice dice1, Dice dice2) {
    for (int i = 0; i < 6; i++) {
        if (dice1.Numbers[i]!= dice2.Numbers[i]) {
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
        int n;
        scanf("%d", &n);
        dice1.Numbers[i] = n;
    }
    for (int i = 0; i < 6; i++) {
        int n;
        scanf("%d", &n);
        dice2.Numbers[i] = n;
    }

    char directionOrder[] = {'N', 'S', 'W', 'E'}; // Order of directions to rotate
    char rollOrder[] = {'R', 'L'}; // Order of rolls
    int flag = 0;

    // Check all possible combinations of rotations and rolls to find if the dice are the same.
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                rotate(&dice2, directionOrder[k], i);
                for (int l = 0; l < 2; l++) {
                    roll(&dice2, rollOrder[l], j);
                    if (isEqual(dice1, dice2)) {
                        flag = 1;
                        goto CHECK;
                    }
                }
            }
        }
    }
CHECK:
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
