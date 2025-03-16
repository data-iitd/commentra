

#include <stdio.h>
#include <math.h>

int main() {
    // Step 1: Take input from the user and split it into a list of integers
    char given[100];
    scanf("%s", given);
    char *token = strtok(given, " ");
    int l1[4];
    for (int i = 0; i < 4; i++) {
        l1[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Step 2: Assign the values to variables x1, y1, x2, and y2
    int x1 = l1[0];
    int y1 = l1[1];
    int x2 = l1[2];
    int y2 = l1[3];

    // Step 3: Check if the denominator is not zero to calculate the quotient
    int denominator = x2 - x1;
    int numerator = y2 - y1;
    float quotient = 0.0;
    if (denominator!= 0) {
        quotient = (float) numerator / denominator;
    }

    // Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
    if (numerator == 0) {
        int d = (int) sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x4 = x1;
        int x3 = x2;
        int y3 = y2 + d;
        int y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
    else if (denominator == 0) {
        int y4 = y2;
        int y3 = y1;
        int d = (int) sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x4 = x1 + d;
        int x3 = x2 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Step 6: If the quotient is 1 or -1, swap the coordinates and print them
    else if (quotient == 1 || quotient == -1) {
        int x4 = x2;
        int x3 = x1;
        int y4 = y1;
        int y3 = y2;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }

    // Step 7: If none of the above conditions are met, print -1
    else {
        printf("-1\n");
    }

    return 0;
}
