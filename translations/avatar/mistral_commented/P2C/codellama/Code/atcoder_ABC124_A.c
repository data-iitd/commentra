#include <stdio.h>

int main()
{
    int a, b, c = 0;

    // Get two integers as input from the user, separated by a space
    scanf("%d %d", &a, &b);

    // Loop through the given condition for 2 times
    for (int i = 0; i < 2; i++)
    {
        // Calculate the sum of the larger number in each iteration and add it to the variable 'c'
        c += (a > b) ? a : b;

        // Update the smaller number in each iteration
        (a > b) ? a-- : b--;
    }

    // Print the final result
    printf("%d", c);

    return 0;
}

