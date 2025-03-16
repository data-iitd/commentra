
#include <stdio.h> // Include the standard input/output library

int main() {
    char s[101]; // Declare a character array to store the input string
    int x = 0, y = 0, k = 0, dx, dy; // Declare variables for coordinates and loop counters
    int co[2][101]; // Declare a 2D array to store the coordinates
    char ch; // Declare a character variable to store the input character
    bool flag = true; // Declare a boolean variable to check for "BUG" pattern

    printf("Enter the input string: "); // Prompt the user to enter the input string
    scanf("%s", s); // Read the input string from the user

    co[0][k] = x; // Store the initial x-coordinate
    co[1][k] = y; // Store the initial y-coordinate
    ++k; // Increment the counter for storing coordinates

    // Update the positions based on the direction commands
    for (int i = 0; s[i]!= '\0'; ++i) {
        ch = s[i]; // Store the current character in the ch variable
        switch (ch) {
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
    if (flag) printf("OK\n"); // Print "OK" if no "bug" pattern is found
    else printf("BUG\n"); // Print "BUG" if a "bug" pattern is found

    return 0; // Return 0 to indicate successful execution
}
