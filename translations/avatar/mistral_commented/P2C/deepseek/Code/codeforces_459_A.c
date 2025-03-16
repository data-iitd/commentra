#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int denominator, numerator, quotient;
    char input[100];
    char *token;

    // Get user input and convert it to a list of integers
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    x1 = atoi(token);
    token = strtok(NULL, " ");
    y1 = atoi(token);
    token = strtok(NULL, " ");
    x2 = atoi(token);
    token = strtok(NULL, " ");
    y2 = atoi(token);

    // Calculate the denominator and numerator of the slope
    denominator = x2 - x1;
    numerator = y2 - y1;

    // Check if the denominator is zero
    if (denominator == 0) {
        // Calculate the distance between the two points and print the result
        int d = (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        x3 = x1;
        y3 = y2 + d;
        x4 = x2;
        y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    // If the denominator is not zero, calculate the quotient
    else if (denominator != 0) {
        quotient = numerator / denominator;

        // Check if the quotient is equal to 1 or -1
        if (quotient == 1 || quotient == -1) {
            // Swap the x and y coordinates of the two points and print the result
            if (quotient == 1) {
                x3 = x2;
                y3 = y1;
                x4 = x1;
                y4 = y2;
            } else {
                x3 = x1;
                y3 = y2;
                x4 = x2;
                y4 = y1;
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
