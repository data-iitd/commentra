#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *p[100];
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int i, j;

    // Take input from the user and split it using a space as the delimiter
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Tokenize the input string
    p[0] = strtok(input, " ");
    for (i = 1; i < 5; i++) {
        p[i] = strtok(NULL, " ");
    }

    // Extract the first four elements of the list p and convert them to integers
    x1 = atoi(p[0]);
    y1 = atoi(p[1]);
    x2 = atoi(p[2]);
    y2 = atoi(p[3]);

    // Calculate the differences between the coordinates
    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;

    // Calculate the coordinates of the other two points based on the given coordinates and the differences
    x3 = x2 - DIF2;
    y3 = y2 + DIF1;
    x4 = x1 - DIF2;
    y4 = y1 + DIF1;

    // Print the calculated coordinates in the format x3 x4 y3 y4
    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}
