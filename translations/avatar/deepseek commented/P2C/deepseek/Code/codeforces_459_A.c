#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char given[100];
    int l1[4];
    int x1, y1, x2, y2;
    float quotient;
    int denominator, numerator;
    int d, x3, y3, x4, y4;

    // Step 1: Take input from the user and split it into a list of integers
    fgets(given, sizeof(given), stdin);
    char *token = strtok(given, " ");
    int i = 0;
    while (token != NULL) {
        l1[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Step 2: Assign the values to variables x1, y1, x2, and y2
    x1 = l1[0];
    y1 = l1[1];
    x2 = l1[2];
    y2 = l1[3];

    // Step 3: Check if the denominator is not zero to calculate the quotient
    denominator = x2 - x1;
    numerator = y2 - y1;
    if (denominator != 0) {
        quotient = (float)numerator / denominator;
    }

    // Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
    if (numerator == 0) {
        d = (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        x4 = x1;
        x3 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
    else if (denominator == 0) {
        y4 = y2;
        y3 = y1;
        d = (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        x4 = x1 + d;
        x3 = x2 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Step 6: If the quotient is 1 or -1, swap the coordinates and print them
    else if (quotient == 1) {
        x4 = x2;
        x3 = x1;
        y4 = y1;
        y3 = y2;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else if (quotient == -1) {
        x4 = x1;
        x3 = x2;
        y4 = y2;
        y3 = y1;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Step 7: If none of the above conditions are met, print -1
    else {
        printf("-1\n");
    }

    return 0;
}
