#include <stdio.h>
#include <math.h>  // Include the math library for mathematical operations

int main() {
    int x1, y1, x2, y2;  // Declare variables for coordinates
    int numerator, denominator, d;  // Declare variables for slope calculation and distance
    double quotient;  // Declare variable for slope

    // Take input from the user
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Calculate the denominator and numerator for slope calculation
    denominator = x2 - x1;
    numerator = y2 - y1;

    // Check if the line is not vertical
    if (denominator != 0) {
        quotient = (double)numerator / denominator;  // Calculate the slope of the line
    }

    // Check if the line is horizontal
    if (numerator == 0) {
        // Calculate the distance between the two points
        d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        // Set new coordinates for the points shifted vertically
        int x3 = x2, y3 = y2 + d;
        int x4 = x1, y4 = y1 + d;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // Check if the line is vertical
    else if (denominator == 0) {
        // Set y-coordinates to the original y-values
        int y3 = y1, y4 = y2;
        // Calculate the distance between the two points
        d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        // Set new coordinates for the points shifted horizontally
        int x3 = x2 + d, x4 = x1 + d;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // Check if the slope is 1 (45 degrees)
    else if (quotient == 1) {
        // Set new coordinates for the points
        int x3 = x1, y3 = y1, x4 = x2, y4 = y2;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // Check if the slope is -1 (-45 degrees)
    else if (quotient == -1) {
        // Set new coordinates for the points
        int x3 = x2, y3 = y2, x4 = x1, y4 = y1;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // If none of the conditions are met, print -1
    else {
        printf("-1\n");
    }

    return 0;  // Return success
}

// <END-OF-CODE>
