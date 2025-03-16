#include <stdio.h>

int main() {
    // Declare variables to hold two integers and the results
    int a, b, x, y;

    // Read two integers from user input
    scanf("%d%d", &a, &b);

    // Calculate the product of a and b
    x = a * b;

    // Calculate the perimeter of a rectangle with sides a and b
    y = (a + b) * 2;

    // Print the results: product and perimeter
    printf("%d %d\n", x, y);

    // Return 0 to indicate successful completion of the program
    return 0;
}
