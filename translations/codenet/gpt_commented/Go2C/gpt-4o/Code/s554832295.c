#include <stdio.h>

int main() {
    // Declare variables to hold the coordinates of two points
    int x1, y1, x2, y2;
    
    // Read the coordinates of the two points from standard input
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Calculate the differences in x and y coordinates
    int a = x2 - x1; // Difference in x-coordinates
    int b = y2 - y1; // Difference in y-coordinates

    // Calculate the coordinates of the two new points that form a rectangle
    int x3 = x2 - b; // x-coordinate of the third point
    int y3 = y2 + a; // y-coordinate of the third point
    int x4 = x1 - b; // x-coordinate of the fourth point
    int y4 = y1 + a; // y-coordinate of the fourth point

    // Output the coordinates of the two new points
    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
