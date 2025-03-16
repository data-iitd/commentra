
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 6
#define MAX_ROTATE 3
#define MAX_ROLL 3

// Dice struct represents a dice with its six faces numbered.
typedef struct {
    int nums[MAX_NUM];
} Dice;

// rotate method rotates the dice in a specified direction a certain number of times.
void rotate(Dice *d, char direction, int times) {
    times %= MAX_ROTATE;
    switch (direction) {
        case 'W': // Rotate West
            for (int i = 0; i < times; i++) {
                d->nums[0] = d->nums[2];
                d->nums[2] = d->nums[5];
                d->nums[5] = d->nums[3];
                d->nums[3] = d->nums[0];
            }
            break;
        case 'E': // Rotate East
            for (int i = 0; i < times; i++) {
                d->nums[0] = d->nums[3];
                d->nums[2] = d->nums[5];
                d->nums[5] = d->nums[3];
                d->nums[3] = d->nums[0];
            }
            break;
        case 'N': // Rotate North
            for (int i = 0; i < times; i++) {
                d->nums[0] = d->nums[1];
                d->nums[4] = d->nums[5];
                d->nums[5] = d->nums[1];
                d->nums[1] = d->nums[0];
            }
            break;
        case 'S': // Rotate South
            for (int i = 0; i < times; i++) {
                d->nums[5] = d->nums[1];
                d->nums[1] = d->nums[0];
                d->nums[0] = d->nums[4];
                d->nums[4] = d->nums[5];
            }
            break;
    }
}

// roll method rolls the dice in a specified direction a certain number of times.
void roll(Dice *d, char direction, int times) {
    times %= MAX_ROLL;
    switch (direction) {
        case 'R': // Roll Right
            for (int i = 0; i < times; i++) {
                d->nums[3] = d->nums[1];
                d->nums[1] = d->nums[2];
                d->nums[2] = d->nums[4];
                d->nums[4] = d->nums[3];
            }
            break;
        case 'L': // Roll Left
            for (int i = 0; i < times; i++) {
                d->nums[3] = d->nums[4];
                d->nums[1] = d->nums[3];
                d->nums[2] = d->nums[1];
                d->nums[4] = d->nums[2];
            }
            break;
    }
}

// printStatus method prints the current status of the dice in a formatted manner.
void printStatus(Dice *d) {
    char status[100] =
        "     _ _ _ _\n"
        " _ _ _|_%3d_|_ _ _ _ _ _\n"
        "|_%3d_|_%3d_|_%3d_|_%3d_|\n"
        "       |_%3d_|\n";
    printf(status, d->nums[0], d->nums[3], d->nums[1], d->nums[2], d->nums[4], d->nums[5]);
    printf("\n");
}

// getIndex function returns the index of a target number in the nums slice.
int getIndex(int *nums, int target) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (target == nums[i]) {
            return i; // Found the target, return its index
        }
    }
    return -1; // Target not found, return -1
}

// isEqual method checks if two dice are in the same state (same numbers on each face).
int isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (d1->nums[i] != d2->nums[i]) {
            return 0; // If any face differs, return false
        }
    }
    return 1; // All faces match, return true
}

// main function to execute the dice comparison logic.
int main() {
    // Initialize two dice
    Dice dice1 = {0};
    Dice dice2 = {0};

    // Input numbers for the first dice
    for (int i = 0; i < MAX_NUM; i++) {
        int n;
        scanf("%d", &n); // Read input for each face
        dice1.nums[i] = n; // Assign input to the dice
    }

    // Input numbers for the second dice
    for (int i = 0; i < MAX_NUM; i++) {
        int n;
        scanf("%d", &n); // Read input for each face
        dice2.nums[i] = n; // Assign input to the dice
    }

    // Define the order of directions and rolls for testing
    char directionOrder[4] = {'N', 'S', 'W', 'E'};
    char rollOrder[2] = {'R', 'L'};
    int flag = 0; // Flag to indicate if a match is found

    CHECK: // Label for breaking out of nested loops
    // Check all combinations of rotations and rolls
    for (int i = 0; i <= MAX_ROTATE; i++) { // Rotate 0 to 2 times
        for (int j = 0; j <= MAX_ROLL; j++) { // Roll 0 to 2 times
            for (int k = 0; k < 4; k++) { // Iterate through directions
                for (int l = 0; l < 2; l++) { // Iterate through roll directions
                    Dice tmp = {0}; // Create a temporary dice
                    for (int m = 0; m < MAX_NUM; m++) { // Copy the numbers from dice2
                        tmp.nums[m] = dice2.nums[m];
                    }
                    rotate(&tmp, directionOrder[k], i); // Rotate the temporary dice
                    roll(&tmp, rollOrder[l], j); // Roll the temporary dice
                    if (isEqual(&tmp, &dice1)) { // Check if it matches dice1
                        flag = 1; // Match found
                        break CHECK; // Break out of all loops
                    }
                }
            }
        }
    }
    // Output the result based on the flag
    if (flag) {
        printf("Yes\n"); // If a match was found
    } else {
        printf("No\n"); // If no match was found
    }
    return 0;
}

