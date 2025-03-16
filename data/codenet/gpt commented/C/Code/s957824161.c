#include <stdio.h>

// Declare global variables for storing two integers
int x, y;

int main() {
    // Read two integers from user input
    scanf("%d %d", &x, &y);
    
    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    printf("%d %d\n", x * y, 2 * x + 2 * y);
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
