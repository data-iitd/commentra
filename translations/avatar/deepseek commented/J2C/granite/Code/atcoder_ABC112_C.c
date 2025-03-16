
#include <stdio.h> // Include the standard input/output library
#define MAX 100 // Define a constant MAX for the maximum value

int main() {
    int n, x[MAX], y[MAX], h[MAX], cx, cy, ch; // Declare variables for the number of points, coordinates, heights, and center coordinates

    // Read the number of points from the user input
    scanf("%d", &n);

    // Read the coordinates and heights of each point from the user input
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &h[i]);
    }

    // Iterate over a range of possible coordinates (i, j) up to MAX
    for (cx = 0; cx <= MAX; cx++) {
        for (cy = 0; cy <= MAX; cy++) {
            ch = check(n, x, y, h, cx, cy); // Call the check function to determine if it is a valid center
            if (ch > 0) { // If the check function returns a valid height
                printf("%d %d %d\n", cx, cy, ch); // Print the center coordinates and height
            }
        }
    }

    return 0; // Return 0 to indicate successful execution
}

// Check function to determine if a point (cx, cy) is a valid center
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
        if (h[i]!= max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            return -1; // If any point does not match, return -1
        }
    }
    return ch; // Return the calculated height if all points match
}

// End of code
