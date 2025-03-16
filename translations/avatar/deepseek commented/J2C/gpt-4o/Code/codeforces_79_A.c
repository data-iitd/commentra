#include <stdio.h> // Including standard input-output library

// The canTake function checks if the resources are sufficient to meet the requirements
int canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) {
    if (xNeeded > xAvailable) return 0; // Check if xNeeded is more than xAvailable
    if (yNeeded > yAvailable) return 0; // Check if yNeeded is more than yAvailable
    return 1; // Return 1 if both conditions are satisfied
}

int main() {
    int x, y; // Variables to hold the available resources
    scanf("%d %d", &x, &y); // Reading the input values for x and y
    int turn = 0; // Initializing the turn counter

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
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
