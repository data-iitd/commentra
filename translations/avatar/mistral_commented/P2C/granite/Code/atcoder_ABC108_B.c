
#include <stdio.h>

int main() {
    int x1, y1, x2, y2, DIF1, DIF2, x3, y3, x4, y4;

    // Take input from the user and split it using a space as the delimiter
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Calculate the differences between the coordinates
    DIF1 = x2 - x1;
    DIF2 = y2 - y1;

    // Calculate the coordinates of the other two points based on the given coordinates and the differences
    x3 = x2 - DIF2;
    y3 = y2 + DIF1;
    x4 = x1 - DIF2;
    y4 = y1 + DIF1;

    // Print the calculated coordinates in the format x3 x4 y3 y4
    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}
