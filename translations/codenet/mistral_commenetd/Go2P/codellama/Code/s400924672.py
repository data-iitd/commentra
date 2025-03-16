# Package declaration
# Importing the required package
import math

# Function definition for the main function
def main():
    # Declaring variables r, D, and x of type int
    r, D, x = 0, 0, 0

    # Reading input values for r, D, and x from the standard input
    r, D, x = map(int, input().split())

    # Comment for the for loop
    # Loop runs 10 times
    for i in range(1, 11):
        # Print the result of the current iteration
        print(r * x - D)

        # Update the value of x for the next iteration
        x = r * x - D

# End of the code
