#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Function to check the height at a given coordinate (cx, cy)
int check(int n, int* x, int* y, int* h, int cx, int cy) {
    int ch = -1;

    // Calculate the initial height based on the first point with a positive height
    for (int i = 0; i < n; i++) {
        if (h[i] > 0) {
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
            break;
        }
    }

    // Validate the height against all points
    for (int i = 0; i < n; i++) {
        // If the calculated height does not match the expected height, return -1
        if (h[i] != fmax(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            return -1;
        }
    }

    // Return the calculated height if all checks pass
    return ch;
}

int main() {
    // Create a variable to read the number of points
    int n;
    scanf("%d", &n);

    // Initialize arrays to store x, y coordinates and heights
    int* x = (int*)malloc(n * sizeof(int));
    int* y = (int*)malloc(n * sizeof(int));
    int* h = (int*)malloc(n * sizeof(int));

    // Read the x, y coordinates and heights for each point
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &h[i]);
    }

    // Iterate through all possible coordinates (i, j) within the defined range
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            // Check the height at the current coordinate (i, j)
            int ch = check(n, x, y, h, i, j);
            // If the height is valid (greater than 0), print the coordinates and height
            if (ch > 0) {
                printf("%d %d %d\n", i, j, ch);
            }
        }
    }

    // Free allocated memory
    free(x);
    free(y);
    free(h);

    return 0;
}

// <END-OF-CODE>
