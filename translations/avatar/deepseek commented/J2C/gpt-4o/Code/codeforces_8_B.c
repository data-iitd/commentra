#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <string.h> // Including string library for string manipulation

int main() {
    int i, j, x = 0, y = 0, k = 0, dx, dy; // Initializing variables for coordinates and loop counters
    int flag = 1; // Flag to check for "BUG" pattern
    char s[101]; // Variable to store the input string
    int co[2][101]; // 2D array to store the coordinates

    scanf("%s", s); // Reading the input string
    co[0][k] = x; // Storing the initial x-coordinate
    co[1][k] = y; // Storing the initial y-coordinate
    ++k; // Incrementing the counter for storing coordinates

    // Updating the positions based on the direction commands
    for (i = 0; i < strlen(s); ++i) {
        switch (s[i]) {
            case 'L': --x; break; // Moving left
            case 'R': ++x; break; // Moving right
            case 'U': ++y; break; // Moving up
            case 'D': --y; break; // Moving down
        }
        co[0][k] = x; // Storing the updated x-coordinate
        co[1][k] = y; // Storing the updated y-coordinate
        ++k; // Incrementing the counter for storing coordinates
    }

    // Checking for "BUG" pattern
    for (i = 0; i < k - 3; ++i) {
        for (j = i + 3; j < k; ++j) {
            dx = co[0][i] - co[0][j]; // Calculating the difference in x-coordinates
            dy = co[1][i] - co[1][j]; // Calculating the difference in y-coordinates
            if (dx < 0) dx *= -1; // Taking the absolute value of dx
            if (dy < 0) dy *= -1; // Taking the absolute value of dy
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Checking if the movement forms a "bug" pattern
                flag = 0; // Setting the flag to false if a "bug" pattern is found
                break; // Breaking out of the inner loop
            }
        }
        if (!flag) break; // Breaking out of the outer loop if a "bug" pattern is found
    }

    // Outputting the result
    if (flag) printf("OK\n"); // Printing "OK" if no "bug" pattern is found
    else printf("BUG\n"); // Printing "BUG" if a "bug" pattern is found

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
