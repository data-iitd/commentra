#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4, denominator, numerator, d;
    double quotient;
    char given[100];
    char *token;

    // Take input from the user and split it into a list of strings
    fgets(given, sizeof(given), stdin);
    token = strtok(given, " ");
    x1 = atoi(token);
    token = strtok(NULL, " ");
    y1 = atoi(token);
    token = strtok(NULL, " ");
    x2 = atoi(token);
    token = strtok(NULL, " ");
    y2 = atoi(token);

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
        d = (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        // Set new coordinates for the points shifted vertically
        x4 = x1;
        x3 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Check if the line is vertical
    else if (denominator == 0) {
        // Set y-coordinates to the original y-values
        y4 = y2;
        y3 = y1;
        // Calculate the distance between the two points
        d = (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        // Set new coordinates for the points shifted horizontally
        x4 = x1 + d;
        x3 = x2 + d;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Check if the slope is 1 (45 degrees)
    else if (quotient == 1.0) {
        // Set new coordinates for the points
        x4 = x2;
        x3 = x1;
        y4 = y1;
        y3 = y2;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Check if the slope is -1 (-45 degrees)
    else if (quotient == -1.0) {
        // Set new coordinates for the points
        x4 = x1;
        x3 = x2;
        y4 = y2;
        y3 = y1;
        // Print the new coordinates
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // If none of the conditions are met, print -1
    else {
        printf("-1\n");
    }

    return 0;
}
