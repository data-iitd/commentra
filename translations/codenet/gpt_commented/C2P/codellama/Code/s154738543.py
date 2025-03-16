#include <stdio.h>

int main(void) {
    # Declare two integer variables x and y
    x, y = 0, 0

    # Read an integer value from the user and store it in variable x
    x = int(input())

    # Calculate the cube of x and store the result in variable y
    y = x ** 3

    # Print the result (the cube of x) to the console
    print(y)

    # Return 0 to indicate successful completion of the program
    return 0
}
