#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    char *p;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int DIF1, DIF2;

    // Read input from the user
    fgets(input, sizeof(input), stdin);

    // Split the input into a list of strings
    p = strtok(input, " ");
    x1 = atoi(p);
    p = strtok(NULL, " ");
    y1 = atoi(p);
    p = strtok(NULL, " ");
    x2 = atoi(p);
    p = strtok(NULL, " ");
    y2 = atoi(p);

    // Calculate the differences in x and y coordinates between the two points
    DIF1 = x2 - x1;  // Difference in x-coordinates
    DIF2 = y2 - y1;  // Difference in y-coordinates

    // Calculate the coordinates of the third point based on the differences
    x3 = x2 - DIF2;  // x-coordinate of the third point
    y3 = y2 + DIF1;  // y-coordinate of the third point

    // Calculate the coordinates of the fourth point based on the differences
    x4 = x1 - DIF2;  // x-coordinate of the fourth point
    y4 = y1 + DIF1;  // y-coordinate of the fourth point

    // Print the coordinates of the third and fourth points
    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}
