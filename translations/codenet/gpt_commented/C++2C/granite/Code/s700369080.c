
#include <stdio.h>

int main() {
    // Declare variables to hold the coordinates of two points
    long long x1, x2, y1, y2;
    
    // Input the coordinates of the two points from the user
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    
    // Calculate the differences in x and y coordinates
    const long long dx = x2 - x1; // Difference in x-coordinates
    const long long dy = y2 - y1; // Difference in y-coordinates
    
    // Calculate the coordinates of the two new points that form a rectangle
    long long x3 = x2 - dy; // x-coordinate of the third point
    long long y3 = y2 + dx; // y-coordinate of the third point
    long long x4 = x1 - dy; // x-coordinate of the fourth point
    long long y4 = y1 + dx; // y-coordinate of the fourth point
    
    // Output the coordinates of the two new points
    printf("%lld %lld %lld %lld\n", x3, y3, x4, y4);
    
    return 0; // Indicate that the program ended successfully
}
