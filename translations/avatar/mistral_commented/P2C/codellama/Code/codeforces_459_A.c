#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declare variables
    int x1, y1, x2, y2, x3, y3, x4, y4, d;
    float numerator, denominator, quotient;

    // Get user input and convert it to a list of integers
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Calculate the denominator and numerator of the slope
    denominator = x2 - x1;
    numerator = y2 - y1;

    // Check if the denominator is zero
    if (denominator == 0)
    {
        // Calculate the distance between the two points and print the result
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        x4 = x1 + d;
        x3 = x2 + d;
        y3 = y1 + d;
        y4 = y2 + d;
        printf("%d %d %d %d", x3, y3, x4, y4);
    }

    // If the denominator is not zero, calculate the quotient
    else if (denominator != 0)
    {
        quotient = numerator / denominator;

        // Check if the quotient is equal to 1 or -1
        if (quotient == 1 || quotient == -1)
        {
            // Swap the x and y coordinates of the two points and print the result
            if (quotient == 1)
            {
                x4 = x2;
                x3 = x1;
                y3 = y1;
                y4 = y2;
            }
            else
            {
                x4 = x1;
                x3 = x2;
                y3 = y2;
                y4 = y1;
            }
            printf("%d %d %d %d", x3, y3, x4, y4);
        }

        // If the quotient is not 1 or -1, print -1
        else
        {
            printf("-1");
        }
    }

    // End of code
    printf("