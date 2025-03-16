
#include <stdio.h>
#include <math.h>

int main() {
    // Get user input and convert it to a list of integers
    int l1[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &l1[i]);
    }

    // Assign the first two elements of the list to x1, y1 and the last two elements to x2, y2
    int x1 = l1[0], y1 = l1[1];
    int x2 = l1[2], y2 = l1[3];

    // Calculate the denominator and numerator of the slope
    int denominator = x2 - x1;
    int numerator = y2 - y1;

    // Check if the denominator is zero
    if (denominator == 0) {
        // Calculate the distance between the two points and print the result
        int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x3 = x1, x4 = x2, y3 = y2 + d, y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // If the denominator is not zero, calculate the quotient
    else if (denominator!= 0) {
        float quotient = (float)numerator / denominator;

        // Check if the quotient is equal to 1 or -1
        if (quotient == 1 || quotient == -1) {
            // Swap the x and y coordinates of the two points and print the result
            if (quotient == 1) {
                int x3 = x2, x4 = x1, y3 = y1, y4 = y2;
            } else {
                int x3 = x1, x4 = x2, y3 = y2, y4 = y1;
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
