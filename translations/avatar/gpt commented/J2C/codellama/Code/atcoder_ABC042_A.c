#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a BufferedReader to read input from the console
    char line[100];
    char *list[100];
    int x, a, y;
    char h[100] = "NO";

    // Read a line of input and split it into an array of strings
    fgets(line, 100, stdin);
    list[0] = strtok(line, " ");
    list[1] = strtok(NULL, " ");
    list[2] = strtok(NULL, " ");

    // Parse the first three elements of the input into integers
    x = atoi(list[0]);
    a = atoi(list[1]);
    y = atoi(list[2]);

    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7)
    {
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17)
        {
            strcpy(h, "YES");
        }
    }

    // Output the result
    printf("%s\n", h);

    return 0;
}

