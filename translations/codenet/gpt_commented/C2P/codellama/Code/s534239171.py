#include<stdio.h>

int main(void) {
    # Declare variables to hold two integers and their average
    a, b, n = 0, 0, 0

    # Read two integers from user input
    a, b = input("Enter two integers: ").split()

    # Calculate the average of the two integers
    n = (a + b) / 2

    # Print the calculated average
    print(n)

    # Return 0 to indicate successful completion of the program
    return 0
}

