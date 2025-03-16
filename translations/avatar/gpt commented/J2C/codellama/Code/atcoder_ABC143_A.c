#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    char str[100];

    // Create a BufferedReader to read input from the console
    // Read a line of input, trim whitespace, and split it into an array of strings
    scanf("%s", str);
    sscanf(str, "%d %d", &a, &b);

    // Parse the first and second elements of the array as integers
    // Calculate the value of c based on the formula: c = a - b * 2
    c = a - b * 2;

    // If c is negative, set it to 0
    if (c < 0)
        c = 0;

    // Output the final value of c
    printf("%d\n", c);

    // Handle any exceptions that may occur during input or processing
    // Handle any exceptions that may occur during input or processing

    return 0;
}

