#include<stdio.h>

# Function prototype declaration for 'you' which takes two integers and returns an integer
def you(x, y):
    pass

def main():
    # Declare variables to hold input values and result
    x = 0
    y = 0
    z = 0

    # Read two integers from user input
    x, y = map(int, input().split())

    # Call the 'you' function with the larger and smaller of the two integers
    if (x >= y):
        z = you(x, y) # If x is greater than or equal to y, pass x and y to 'you'
    else:
        z = you(y, x) # Otherwise, pass y and x to 'you'

    # Print the result returned from the 'you' function
    print(z)

    # Return 0 to indicate successful completion of the program
    return 0

# Function 'you' that computes the greatest common divisor (GCD) using the Euclidean algorithm
def you(x, y):
    z = 0

    # Infinite loop to perform the Euclidean algorithm
    while (1):
        z = x % y # Calculate the remainder of x divided by y
        x = y     # Update x to be y
        y = z     # Update y to be the remainder

        # Break the loop if y becomes zero or negative
        if (y <= 0):
            break

    # Return the last non-zero value of x, which is the GCD
    return x

# 