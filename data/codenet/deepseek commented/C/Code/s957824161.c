#include <stdio.h> // Include the standard input/output library

int x, y; // Declare two integer variables to store user input

int main() { // Define the main function, the entry point of the program
    scanf("%d %d", &x, &y); // Read two integers from the standard input and store them in x and y
    printf("%d %d\n", x * y, 2 * x + 2 * y); // Print the product of x and y and the perimeter of the rectangle
    return 0; // Return 0 to indicate successful execution
}
