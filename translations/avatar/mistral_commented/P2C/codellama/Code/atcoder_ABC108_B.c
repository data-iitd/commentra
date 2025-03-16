#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Take input from the user and split it using a space as the delimiter
    char *p[4];
    int i = 0;
    char *token = strtok(NULL, " ");
    while (token != NULL)
    {
        p[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    // Extract the first four elements of the list p and convert them to integers
    int x1 = atoi(p[0]);
    int y1 = atoi(p[1]);
    int x2 = atoi(p[2]);
    int y2 = atoi(p[3]);

    // Calculate the differences between the coordinates
    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;

    // Calculate the coordinates of the other two points based on the given coordinates and the differences
    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;
    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;

    // Print the calculated coordinates in the format x3 x4 y3 y4
    printf("%d %d %d %d", x3, y3, x4, y4);

    return 0;
}
