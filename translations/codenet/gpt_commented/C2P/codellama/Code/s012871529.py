#include <stdio.h>

int main() {
    # Declare two integer variables to hold the input values
    a, b = input("Enter two integers: ").split()

    # Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
    print(a * b, 2 * (a + b))

    # Return 0 to indicate successful execution of the program
    return 0
}
