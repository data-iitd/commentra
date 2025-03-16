#include <stdio.h>
#include <stdbool.h>

#define NUM_FACES 6

// Dice struct represents a dice with its six faces numbered.
typedef struct {
    int nums[NUM_FACES]; // Array to hold the numbers on the faces of the dice
} Dice;

// rotate function rotates the dice in a specified direction a certain number of times.
void rotate(Dice *d, const char *direction, int times) {
    times %= 4; // Normalize the number of rotations to be within 0-3
    for (int i = 0; i < times; i++) {
        if (direction[0] == 'W') { // Rotate West
            int temp = d->nums[0];
            d->nums[0] = d->nums[2];
            d->nums[2] = d->nums[5];
            d->nums[5] = d->nums[3];
            d->nums[3] = temp;
        } else if (direction[0] == 'E') { // Rotate East
            int temp = d->nums[0];
            d->nums[0] = d->nums[3];
            d->nums[3] = d->nums[5];
            d->nums[5] = d->nums[2];
            d->nums[2] = temp;
        } else if (direction[0] == 'N') { // Rotate North
            int temp = d->nums[0];
            d->nums[0] = d->nums[1];
            d->nums[1] = d->nums[5];
            d->nums[5] = d->nums[4];
            d->nums[4] = temp;
        } else if (direction[0] == 'S') { // Rotate South
            int temp = d->nums[5];
            d->nums[5] = d->nums[1];
            d->nums[1] = d->nums[0];
            d->nums[0] = d->nums[4];
            d->nums[4] = temp;
        }
    }
}

// roll function rolls the dice in a specified direction a certain number of times.
void roll(Dice *d, const char *direction, int times) {
    times %= 4; // Normalize the number of rolls to be within 0-3
    for (int i = 0; i < times; i++) {
        if (direction[0] == 'R') { // Roll Right
            int temp = d->nums[3];
            d->nums[3] = d->nums[1];
            d->nums[1] = d->nums[2];
            d->nums[2] = d->nums[4];
            d->nums[4] = temp;
        } else if (direction[0] == 'L') { // Roll Left
            int temp = d->nums[3];
            d->nums[3] = d->nums[4];
            d->nums[4] = d->nums[2];
            d->nums[2] = d->nums[1];
            d->nums[1] = temp;
        }
    }
}

// printStatus function prints the current status of the dice in a formatted manner.
void printStatus(Dice *d) {
    printf("         ___\n");
    printf("    ____|_%3d_|_______\n", d->nums[0]);
    printf("    |_4_|_%3d_|_%3d_|_%3d_|\n", d->nums[3], d->nums[1], d->nums[2]);
<<<<<<< HEAD
    printf("        |_5_|\n", d->nums[4]);
=======
    printf("        |_5_|\n\n");
>>>>>>> 98c87cb78a (data updated)
}

// isEqual function checks if two dice are in the same state (same numbers on each face).
bool isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < NUM_FACES; i++) {
        if (d1->nums[i] != d2->nums[i]) {
            return false; // If any face differs, return false
        }
    }
    return true; // All faces match, return true
}

// main function to execute the dice comparison logic.
int main() {
    // Initialize two dice
    Dice dice1, dice2;

    // Input numbers for the first dice
    for (int i = 0; i < NUM_FACES; i++) {
        scanf("%d", &dice1.nums[i]); // Read input for each face
    }

    // Input numbers for the second dice
    for (int i = 0; i < NUM_FACES; i++) {
        scanf("%d", &dice2.nums[i]); // Read input for each face
    }

    // Define the order of directions and rolls for testing
    const char *directionOrder[] = {"N", "S", "W", "E"};
    const char *rollOrder[] = {"R", "L"};
    bool flag = false; // Flag to indicate if a match is found

    // Check all combinations of rotations and rolls
    for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
        for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
            for (int d = 0; d < 4; d++) { // Iterate through directions
                for (int r = 0; r < 2; r++) { // Iterate through roll directions
                    Dice tmp = dice2; // Create a temporary dice
                    rotate(&tmp, directionOrder[d], i); // Rotate the temporary dice
                    roll(&tmp, rollOrder[r], j); // Roll the temporary dice
                    if (isEqual(&tmp, &dice1)) { // Check if it matches dice1
                        flag = true; // Match found
                        break; // Break out of all loops
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }

    // Output the result based on the flag
    if (flag) {
        printf("Yes\n"); // If a match was found
    } else {
        printf("No\n"); // If no match was found
    }

    return 0;
}

// <END-OF-CODE>
