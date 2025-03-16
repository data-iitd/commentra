#include <stdio.h>

int main()
{
    int r, D, x;
    int i;

    // Read three integers r, D, and x from input
    scanf("%d %d %d", &r, &D, &x);

    // Loop from 2 to 11 (inclusive)
    for (i = 2; i <= 11; i++)
    {
        // Calculate the value using the given formula and print the integer result
        printf("%d\n", (int)((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r)));
    }

    return 0;
}

