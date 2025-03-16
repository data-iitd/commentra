#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <string.h> // Including string library for string manipulation

int main() { // Defining the main function
    int i, j, x = 0, y = 0, k = 0, dx, dy; // Declaring and initializing variables
    int flag = 1; // Declaring and initializing a flag variable
    char s[101]; // Declaring a string variable with a maximum size of 100 characters
    int co[2][101]; // Declaring a 2D integer array of size 2 x 101

    scanf("%s", s); // Reading the input string from the console
    co[0][k] = x; co[1][k] = y; // Initializing the first element of the array with x and y values
    ++k; // Incrementing the size of the array

    for (i = 0; i < strlen(s); ++i) { // Loop to iterate through each character in the string
        switch (s[i]) { // Switch statement to handle each character based on its value
            case 'L': --x; // Move x to the left
                break;
            case 'R': ++x; // Move x to the right
                break;
            case 'U': ++y; // Move y up
                break;
            case 'D': --y; // Move y down
                break;
        }
        co[0][k] = x; co[1][k] = y; // Updating the current position in the array
        ++k; // Incrementing the size of the array
    }

    for (i = 0; i < k - 3; ++i) { // Outer loop to iterate through all elements except the last three
        for (j = i + 3; j < k; ++j) { // Inner loop to compare the current element with the next three elements
            dx = co[0][i] - co[0][j]; // Calculate the difference in x-coordinates
            dy = co[1][i] - co[1][j]; // Calculate the difference in y-coordinates
            if (dx < 0) dx *= -1; // Making dx positive if it's negative
            if (dy < 0) dy *= -1; // Making dy positive if it's negative
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) { // Checking if the difference is within 1 unit in either x or y direction
                flag = 0; // Setting the flag to false if a difference of 1 unit is found
                break; // Exiting the inner loop if a difference of 1 unit is found
            }
        }
        if (!flag) break; // Exiting the outer loop if a difference of 1 unit is found in any of the inner loops
    }

    if (flag) printf("OK\n"); // Printing "OK" if no difference of 1 unit is found
    else printf("BUG\n"); // Printing "BUG" if a difference of 1 unit is found

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
