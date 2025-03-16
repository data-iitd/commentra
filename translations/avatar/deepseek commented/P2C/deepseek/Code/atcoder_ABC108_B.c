#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int p[4];
    int x1, y1, x2, y2;
    int DIF1, DIF2;
    int x3, y3, x4, y4;

    // Read input from user
    fgets(input, sizeof(input), stdin);

    // Split input into a list of strings and convert to integers
    sscanf(input, "%d %d %d %d", &p[0], &p[1], &p[2], &p[3]);

    // Assign values to variables
    x1 = p[0];
    y1 = p[1];
    x2 = p[2];
    y2 = p[3];

    // Calculate differences
    DIF1 = x2 - x1;
    DIF2 = y2 - y1;

    // Calculate new coordinates
    x3 = x2 - DIF2;
    y3 = y2 + DIF1;
    x4 = x1 - DIF2;
    y4 = y1 + DIF1;

    // Print coordinates in formatted string
    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}
