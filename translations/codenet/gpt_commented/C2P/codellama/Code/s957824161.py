#include <stdio.h>

# Declare global variables for storing two integers
x, y = 0, 0

def main():
    # Read two integers from user input
    x, y = input("Enter two integers: ").split()
    
    # Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    # Print the results: product and perimeter
    print(x * y, 2 * x + 2 * y)
    
    # Return 0 to indicate successful completion of the program
    return 0

