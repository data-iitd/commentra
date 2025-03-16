#include <stdio.h>
#include <math.h>

int main() {
    // Step 1: Take input from the user and split it into a list of integers
    int x1, y1, x2, y2;
    printf("Enter four integers (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Step 3: Check if the denominator is not zero to calculate the quotient
    int denominator = x2 - x1;
    int numerator = y2 - y1;
    double quotient;

    if (denominator != 0) {
        quotient = (double)numerator / denominator;
    }

    // Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
    if (numerator == 0) {
        int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x3 = x2;
        int y3 = y2 + d;
        int x4 = x1;
        int y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
    else if (denominator == 0) {
        int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int y3 = y1;
        int y4 = y2;
        int x3 = x2 + d;
        int x4 = x1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // Step 6: If the quotient is 1 or -1, swap the coordinates and print them
    else if (quotient == 1) {
        int x3 = x1;
        int y3 = y2;
        int x4 = x2;
        int y4 = y1;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    } else if (quotient == -1) {
        int x3 = x2;
        int y3 = y1;
        int x4 = x1;
        int y4 = y2;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // Step 7: If none of the above conditions are met, print -1
    else {
        printf("-1\n");
    }

    return 0;
}

// <END-OF-CODE>
