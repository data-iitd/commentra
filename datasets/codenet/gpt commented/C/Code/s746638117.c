#include<stdio.h>

int main() {
    // Declare variables to hold the dimensions and results
    int a, b, ar, le;

    // Read the length and width from user input
    scanf("%d %d", &a, &b);

    // Calculate the area of the rectangle (length * width)
    ar = a * b;

    // Calculate the perimeter of the rectangle (2 * (length + width))
    le = 2 * (a + b);

    // Output the calculated area and perimeter
    printf("%d %d\n", ar, le);

    // Return 0 to indicate successful execution
    return 0;
}
