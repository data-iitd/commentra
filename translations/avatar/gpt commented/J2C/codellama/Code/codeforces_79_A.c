#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Method to check if the required resources can be taken
int canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) { 
    // Check if the needed x resources are greater than available
    if (xNeeded > xAvailable) return 0; 
    // Check if the needed y resources are greater than available
    if (yNeeded > yAvailable) return 0; 
    // If both checks pass, return true
    return 1; 
} 

int main() { 
    // Initialize variables to store x and y values
    int x, y; 
    // Initialize turn counter
    int turn = 0; 

    // Read input from stdin
    scanf("%d %d", &x, &y); 

    // Infinite loop to alternate turns between two players
    while (1) { 
        // Check if it's the first player's turn (even turn number)
        if (turn % 2 == 0) { 
            // Try to take resources according to the defined rules
            if (canTake(2, x, 2, y)) { 
                x -= 2; // Deduct resources for the first option
                y -= 2; 
            } else if (canTake(1, x, 12, y)) { 
                x -= 1; // Deduct resources for the second option
                y -= 12; 
            } else if (canTake(0, x, 22, y)) { 
                y -= 22; // Deduct resources for the third option
            } else { 
                // If no options are available, first player loses
                printf("Hanako\n"); 
                return 0; 
            } 
        } else { 
            // Check if it's the second player's turn (odd turn number)
            if (canTake(0, x, 22, y)) { 
                y -= 22; // Deduct resources for the first option
            } else if (canTake(1, x, 12, y)) { 
                x -= 1; // Deduct resources for the second option
                y -= 12; 
            } else if (canTake(2, x, 2, y)) { 
                x -= 2; // Deduct resources for the third option
                y -= 2; 
            } else { 
                // If no options are available, second player loses
                printf("Ciel\n"); 
                return 0; 
            } 
        } 
        turn++; // Increment turn counter for the next iteration
    } 
    return 0; 
} 
