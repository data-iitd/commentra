// Include the necessary header files for input/output and string manipulation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function 'canTake' that checks if the required resources are available
int canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) {
    // Check if the required number of units of the x-resource exceeds the available amount
    if (xNeeded > xAvailable) {
        return 0;
    }

    // Check if the required number of units of the y-resource exceeds the available amount
    if (yNeeded > yAvailable) {
        return 0;
    }

    // If both checks pass, the current turn can take the required resources
    return 1;
}

// Define the main method where the game logic is implemented
int main() {
    // Initialize the input stream and tokenizer
    char input[100];
    char *token;
    int x, y;

    // Read the initial position of the two players (Hanako and Ciel)
    scanf("%s", input);
    token = strtok(input, " ");
    x = atoi(token);
    token = strtok(NULL, " ");
    y = atoi(token);

    // Start the game loop
    int turn = 0;
    while (1) {
        // Check which player's turn it is
        if (turn % 2 == 0) { // Hanako's turn
            if (canTake(2, x, 2, y)) { // Try to move Hanako two units to the left and two units up
                x -= 2;
                y -= 2;
            } else if (canTake(1, x, 12, y)) { // Try to move Hanako one unit to the left and twelve units up
                x -= 1;
                y -= 12;
            } else { // If neither move is possible, print "Hanako" and exit the program
                printf("Hanako\n");
                return 0;
            }
        } else { // Ciel's turn
            if (canTake(0, x, 22, y)) { // Try to move Ciel two units to the right and twenty-two units down
                y -= 22;
            } else if (canTake(1, x, 12, y)) { // Try to move Ciel one unit to the right and twelve units down
                x -= 1;
                y -= 12;
            } else if (canTake(2, x, 2, y)) { // Try to move Ciel two units to the right and two units down
                x -= 2;
                y -= 2;
            } else { // If neither move is possible, print "Ciel" and exit the program
                printf("Ciel\n");
                return 0;
            }
        }

        // Increment the turn number
        turn++;
    }
}

