
#include <iostream> // Include the necessary header file for input/output
#include <string> // Include the necessary header file for strings

using namespace std; // Using the standard namespace

int main() {
    string s; // Declare a string variable to store the input string
    char ch[100]; // Declare a character array to store the input string as characters
    int co[2][101] = {}; // Declare a 2D array to store the coordinates
    int x = 0, y = 0, k = 0, dx, dy; // Declare variables for coordinates and loop counters
    bool flag = true; // Declare a boolean variable to check for "BUG" pattern

    cout << "Enter the input string: "; // Prompt the user to enter the input string
    getline(cin, s); // Read the input string from the user

    for (int i = 0; i < s.length(); ++i) {
        ch[i] = s[i]; // Convert the input string to a character array
    }

    co[0][k] = x; // Store the initial x-coordinate
    co[1][k] = y; // Store the initial y-coordinate
    ++k; // Increment the counter for storing coordinates

    // Update the positions based on the direction commands
    for (int i = 0; i < s.length(); ++i) {
        switch (ch[i]) {
            case 'L': --x; break; // Move left
            case 'R': ++x; break; // Move right
            case 'U': ++y; break; // Move up
            case 'D': --y; break; // Move down
        }
        co[0][k] = x; // Store the updated x-coordinate
        co[1][k] = y; // Store the updated y-coordinate
        ++k; // Increment the counter for storing coordinates
    }

    // Check for "BUG" pattern
    for (int i = 0; i < k - 3; ++i) {
        for (int j = i + 3; j < k; ++j) {
            dx = co[0][i] - co[0][j]; // Calculate the difference in x-coordinates
            dy = co[1][i] - co[1][j]; // Calculate the difference in y-coordinates
            if (dx < 0) dx *= -1; // Take the absolute value of dx
            if (dy < 0) dy *= -1; // Take the absolute value of dy
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Check if the movement forms a "bug" pattern
                flag = false; // Set the flag to false if a "bug" pattern is found
                break; // Break out of the inner loop
            }
        }
        if (!flag) break; // Break out of the outer loop if a "bug" pattern is found
    }

    // Output the result
    if (flag) cout << "OK" << endl; // Print "OK" if no "bug" pattern is found
    else cout << "BUG" << endl; // Print "BUG" if a "bug" pattern is found

    return 0; // Return 0 to indicate successful execution
}
