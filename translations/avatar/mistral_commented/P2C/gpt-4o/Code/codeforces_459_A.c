#include <stdio.h>
#include <math.h>

int main() {
    // Declare variables for the coordinates
    int x1, y1, x2, y2;
    
    // Get user input
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    // Calculate the denominator and numerator of the slope
    int denominator = x2 - x1;
    int numerator = y2 - y1;

    // Check if the denominator is zero
    if (denominator == 0) {
        // Calculate the distance between the two points
        int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x3 = x2, y3 = y2 + d, x4 = x1, y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    } 
    // If the denominator is not zero, calculate the quotient
    else {
        double quotient = (double)numerator / denominator;

        // Check if the quotient is equal to 1 or -1
        if (quotient == 1.0 || quotient == -1.0) {
            int x3, y3, x4, y4;
            // Swap the x and y coordinates of the two points
            if (quotient == 1.0) {
                x3 = x2; y3 = y1; x4 = x1; y4 = y2;
            } else {
                x3 = x1; y3 = y2; x4 = x2; y4 = y1;
            }
            printf("%d %d %d %d\n", x3, y3, x4, y4);
        } 
        // If the quotient is not 1 or -1, print -1
        else {
            printf("-1\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
