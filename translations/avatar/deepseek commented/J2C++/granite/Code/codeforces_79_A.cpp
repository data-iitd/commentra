
#include <iostream> // Include the necessary libraries for input/output operations
#include <string> // Include the necessary library for string manipulation
#include <vector> // Include the necessary library for vector data structure
#include <algorithm> // Include the necessary library for algorithmic functions

using namespace std; // Use the standard namespace for convenience

// The canTake method checks if the resources are sufficient to meet the requirements
bool canTake(int xNeeded, int xAvailable, int yNeeded, int yAvailable) {
    if (xNeeded > xAvailable) return false; // Check if xNeeded is more than xAvailable
    if (yNeeded > yAvailable) return false; // Check if yNeeded is more than yAvailable
    return true; // Return true if both conditions are satisfied
}

int main() {
    int x, y, turn = 0; // Declare and initialize the variables x, y, and turn
    string input; // Declare a string variable for input

    // The main loop where the game alternates between two players based on the turn counter
    while (true) {
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
                cout << "Hanako" << endl;
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
                cout << "Ciel" << endl;
                return 0;
            }
        }
        turn++; // Increment the turn counter
    }

    return 0; // Return 0 to indicate successful execution
}

