#include<stdio.h>

int main() {
    # Declare integer variables to hold the input values and results
    a, b, c, d = 0, 0, 0, 0

    # Read two integer values from user input
    a, b = input("Enter two integers: ").split()

    # Calculate the area of a rectangle (length * width)
    c = a * b

    # Calculate the perimeter of a rectangle (2 * (length + width))
    d = 2 * a + 2 * b

    # Output the calculated area and perimeter
    print(c, d)

    # Return 0 to indicate successful completion of the program
    return 0
}

