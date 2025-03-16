#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a BufferedReader to read input from the console
    char str[100];
    int h, a, num;

    // Read a line of input and split it into an array of strings
    scanf("%s", str);

    // Parse the first string as an integer representing the initial health
    sscanf(str, "%d", &h);

    // Parse the second string as an integer representing the damage dealt per attack
    sscanf(str, "%d", &a);

    // Initialize a counter to keep track of the number of attacks
    num = 0;

    // Loop until the health is greater than zero
    for (int i = 1; h > 0; i++)
    {
        // Decrease health by the amount of damage dealt
        h = h - a;

        // Increment the attack counter
        num++;
    }

    // Output the total number of attacks required to reduce health to zero or below
    printf("%d", num);

    // End of code
    return 0;
}