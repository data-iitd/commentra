#include<stdio.h>

int main()
{
    // Declare variables to hold the lengths of the two bases (a and b) and the height (h)
    int a, b, h;

    // Read the values of the two bases and the height from user input
    scanf("%d%d%d", &a, &b, &h);

    // Calculate the area of the trapezoid using the formula: Area = ((base1 + base2) * height) / 2
    // and print the result
    printf("%d\n", (a + b) * h / 2);

    // Return 0 to indicate successful completion of the program
    return 0;
}
