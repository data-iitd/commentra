#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The canTake method checks if the resources are sufficient to meet the requirements
int canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) {
    if (xNeeded > xAvailable) return 0; // Check if xNeeded is more than xAvailable
    if (yNeeded > yAvailable) return 0; // Check if yNeeded is more than yAvailable
    return 1; // Return true if both conditions are satisfied
}

int main() {
    char input[100]; // Declaring input array to store input string
    int x, y, turn = 0; // Declaring variables for x, y, and turn

    // Reading input string
    fgets(input, 100, stdin);

    // Tokenizing the input string
    char *token = strtok(input, " ");
    x = atoi(token);
    token = strtok(NULL, " ");
    y = atoi(token);

    // The main loop where the game alternates between two players based on the turn counter
    while (1) {
        if (turn % 2 == 0) { // Check if it's Hanako's turn (even turn)
            // Hanako's turn actions: Attempt to take resources in the given order
            if (canTake(2, x, 2, y)) { // Attempt to take 2 from both x and y
                x -= 2;
                y -= 2;
            } else if (canTake(1, x, 12, y)) { // Attempt to take 1 from x and 12 from y
                x -= 1;
                y -= 12;
            } else if (canTake(0, x, 22, y)) { // Attempt to take 22 from y
                y -= 22;
            } else { // If no resources can be taken, Hanako loses
                printf("Hanako\n");
                return 0;
            }
        } else { // It's Ciel's turn (odd turn)
            // Ciel's turn actions: Attempt to take resources in the given order
            if (canTake(0, x, 22, y)) { // Attempt to take 22 from y
                y -= 22;
            } else if (canTake(1, x, 12, y)) { // Attempt to take 1 from x and 12 from y
                x -= 1;
                y -= 12;
            } else if (canTake(2, x, 2, y)) { // Attempt to take 2 from both x and y
                x -= 2;
                y -= 2;
            } else { // If no resources can be taken, Ciel loses
                printf("Ciel\n");
                return 0;
            }
        }
        turn++; // Increment the turn counter
    }
    return 0;
}

