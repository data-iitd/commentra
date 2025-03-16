#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables for the coordinates of the two points
    int x1, y1, x2, y2;

    // Read the coordinates of the two points (x1, y1) and (x2, y2)
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Check if the two points are vertically aligned (same x-coordinate)
    if (x1 == x2) {
        // Calculate the vertical distance between the two points
        int dif = abs(y1 - y2);
        // Output the coordinates of the rectangle formed by the two points
        printf("%d %d %d %d\n", (x1 + dif), y1, (x1 + dif), y2);
    }
    // Check if the two points are horizontally aligned (same y-coordinate)
    else if (y1 == y2) {
        // Calculate the horizontal distance between the two points
        int dif = abs(x1 - x2);
        // Output the coordinates of the rectangle formed by the two points
        printf("%d %d %d %d\n", x1, (y1 + dif), x2, (y2 + dif));
    }
    // Check if the two points form a square (equal distance in both x and y)
    else if (abs(x1 - x2) == abs(y1 - y2)) {
        // Output the coordinates of the rectangle formed by swapping y-coordinates
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    }
    // If none of the above conditions are met, output -1 indicating no rectangle can be formed
    else {
        printf("-1\n");
    }

    return 0;
}

// <END-OF-CODE>
