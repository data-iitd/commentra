#include <stdio.h>
#include <stdbool.h>

#define NUM_SIDES 6

// Define a Dice struct with a Numbers array to store the numbers on the dice.
typedef struct {
    int Nums[NUM_SIDES];
} Dice;

// Function to rotate the dice in a given direction by a given number of times.
void rotate(Dice *d, const char *direction, int times) {
    times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
    for (int i = 0; i < times; i++) {
        if (direction[0] == 'W') { // West direction rotation logic
            int temp = d->Nums[0];
            d->Nums[0] = d->Nums[2];
            d->Nums[2] = d->Nums[5];
            d->Nums[5] = d->Nums[3];
            d->Nums[3] = temp;
        } else if (direction[0] == 'E') { // East direction rotation logic
            int temp = d->Nums[0];
            d->Nums[0] = d->Nums[3];
            d->Nums[3] = d->Nums[5];
            d->Nums[5] = d->Nums[2];
            d->Nums[2] = temp;
        } else if (direction[0] == 'N') { // North direction rotation logic
            int temp = d->Nums[0];
            d->Nums[0] = d->Nums[1];
            d->Nums[1] = d->Nums[5];
            d->Nums[5] = d->Nums[4];
            d->Nums[4] = temp;
        } else if (direction[0] == 'S') { // South direction rotation logic
            int temp = d->Nums[5];
            d->Nums[5] = d->Nums[1];
            d->Nums[1] = d->Nums[0];
            d->Nums[0] = d->Nums[4];
            d->Nums[4] = temp;
        }
    }
}

// Function to roll the dice in a given direction by a given number of times.
void roll(Dice *d, const char *direction, int times) {
    times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
    for (int i = 0; i < times; i++) {
        if (direction[0] == 'R') { // Right direction roll logic
            int temp = d->Nums[3];
            d->Nums[3] = d->Nums[1];
            d->Nums[1] = d->Nums[2];
            d->Nums[2] = d->Nums[4];
            d->Nums[4] = temp;
        } else if (direction[0] == 'L') { // Left direction roll logic
            int temp = d->Nums[4];
            d->Nums[4] = d->Nums[3];
            d->Nums[3] = d->Nums[1];
            d->Nums[1] = d->Nums[2];
            d->Nums[2] = temp;
        }
    }
}

// Function to print the current status of the dice.
void printStatus(Dice *d) {
    printf("        _ _ _ _\n");
    printf("     _ _ _|_%3d_|_ _ _ _ _ _\n", d->Nums[0]);
    printf("    |_%3d_|_%3d_|_%3d_|_%3d_|\n", d->Nums[3], d->Nums[1], d->Nums[2], d->Nums[4]);
    printf("            |_%3d_|\n", d->Nums[5]);
}

// Function to check if two dice have the same numbers.
bool isEqual(Dice *d1, Dice *d2) {
    for (int i = 0; i < NUM_SIDES; i++) {
        if (d1->Nums[i] != d2->Nums[i]) {
            return false;
        }
    }
    return true;
}

// Main function to read user input and check if two dice are the same after certain rotations and rolls.
int main() {
    Dice dice1 = {0};
    Dice dice2 = {0};

    for (int i = 0; i < NUM_SIDES; i++) {
        scanf("%d", &dice1.Nums[i]);
    }
    for (int i = 0; i < NUM_SIDES; i++) {
        scanf("%d", &dice2.Nums[i]);
    }

    const char *directionOrder[] = {"N", "S", "W", "E"}; // Order of directions to rotate
    const char *rollOrder[] = {"R", "L"};               // Order of rolls
    bool flag = false;

    // Check all possible combinations of rotations and rolls to find if the dice are the same.
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 2; l++) {
                    Dice tmp = dice2; // Create a copy of dice2
                    rotate(&tmp, directionOrder[k], i);
                    roll(&tmp, rollOrder[l], j);
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
