
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[100];
    char *list[100];
    int x, a, y;
    char h[100];

    // Create a BufferedReader to read input from the user
    // Read a line of input from the user
    fgets(line, 100, stdin);

    // Split the input line into an array of strings
    list = strtok(line, " ");

    // Parse the first three elements of the array as integers
    x = atoi(list[0]);
    a = atoi(list[1]);
    y = atoi(list[2]);

    // Initialize a variable to store the result
    strcpy(h, "NO");

    // Check if any of the integers is either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7)
    {
        // Check if the sum of the integers is 17
        if (x + y + a == 17)
        {
            strcpy(h, "YES");
        }
    }

    // Print the result
    printf("%s\n", h);

    return 0;
}

