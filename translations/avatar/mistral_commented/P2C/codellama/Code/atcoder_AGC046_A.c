
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x;
    int gcd_value;

    // Ask the user for an integer input and assign it to the variable x
    scanf("%d", &x);

    // Calculate the greatest common divisor (gcd) of 360 and the user input x
    gcd_value = gcd(360, x);

    // Print the result of the division of 360 by the gcd
    printf("%d", 360 / gcd_value);

    return 0;
}

