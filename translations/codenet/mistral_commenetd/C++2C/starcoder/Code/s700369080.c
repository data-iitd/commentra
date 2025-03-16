
#include <stdio.h>

int main(){
    // Define variables to store input coordinates
    int x1, x2, y1, y2;

    // Read input coordinates from standard input
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Calculate differences between final and initial coordinates
    const int dx = x2 - x1, dy = y2 - y1;

    // Calculate coordinates of points to the left and above, and right and below the final point
    int x3 = x2 - dy, y3 = y2 + dx;
    int x4 = x1 - dy, y4 = y1 + dx;

    // Print the calculated coordinates to the standard output
    printf("%d %d %d %d\n", x3, y3, x4, y4);

    // End the program with a return statement of 0
    return 0;
}

