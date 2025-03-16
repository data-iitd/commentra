#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100 // Define a constant MAX for the maximum value

int check(int n, int x[], int y[], int h[], int cx, int cy) {
    int ch = -1; // Initialize ch to -1
    for (int i = 0; i < n; i++) { // Loop through each point
        if (h[i] > 0) { // If the height of the point is greater than 0
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]; // Calculate the height difference
            break; // Break the loop as we found a valid height
        }
    }

    // Verify if the calculated height matches the height of all points
    for (int i = 0; i < n; i++) {
        if (h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            return -1; // If any point does not match, return -1
        }
    }
    return ch; // Return the calculated height if all points match
}

int main() {
    int n; // Declare a variable to store the number of points
    scanf("%d", &n); // Read the number of points from the user input
    int x[n], y[n], h[n]; // Declare arrays to store coordinates and heights

    // Read the coordinates and heights of each point from the user input
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &h[i]);
    }

    // Iterate over a range of possible coordinates (i, j) up to MAX
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            int ch = check(n, x, y, h, i, j); // Call the check function to determine if it is a valid center
            if (ch > 0) { // If the check function returns a valid height
                printf("%d %d %d\n", i, j, ch); // Print the center coordinates and height
            }
        }
    }
    return 0;
}

