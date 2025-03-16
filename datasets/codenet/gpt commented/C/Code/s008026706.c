#include<stdio.h>

int main() {
    // Declare variables to hold the dimensions and results
    int a, b, x, y;

    // Read two integer inputs from the user (representing dimensions)
    scanf("%d%d", &a, &b);

    // Calculate the perimeter of the rectangle (2 * (length + width))
    x = 2 * a + 2 * b;

    // Calculate the area of the rectangle (length * width)
    y = a * b;

    // Output the area and perimeter
    printf("%d %d\n", y, x);

    // Return 0 to indicate successful execution
    return 0;
}
