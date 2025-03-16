#include<stdio.h>

# Function prototype declaration for 'you' which takes two integers and returns an integer
def you(x, y):
    z = x % y
    x = y
    y = z

    if y <= 0:
        return x

    return you(x, y)

def main():
    # Declare variables to hold input values and result
    x, y, z = 0, 0, 0

    # Read two integers from user input
    x, y = input("Enter two integers: ").split()
    x, y = int(x), int(y)

    # Call the 'you' function with the larger and smaller of the two integers
    if x >= y:
        z = you(x, y) # If x is greater than or equal to y, pass x and y to 'you'
    else:
        z = you(y, x) # Otherwise, pass y and x to 'you'

    # Print the result returned from the 'you' function
    print(z)

    # Return 0 to indicate successful completion of the program
    return 0

# Call the main function
main()

