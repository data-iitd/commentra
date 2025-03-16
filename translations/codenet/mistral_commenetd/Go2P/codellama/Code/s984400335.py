# Package declaration

# Importing the 'sys' package for input/output operations
import sys

# Function declaration for finding the minimum number among given integers
def min(nums):
    # Initializing the minimum value with the first integer
    min = nums[0]

    # Iterating through the list 'nums' to find the minimum value
    for v in nums:
        # If the current value is less than the minimum value, update the minimum value
        if v < min:
            min = v

    # Returning the minimum value
    return min

# Main function declaration
def main():
    # Declaring three integer variables for reading input values
    n, a, b = 0, 0, 0

    # Reading input values from the standard input using 'sys.stdin.readline' function
    n, a, b = map(int, sys.stdin.readline().split())

    # Printing the minimum value between 'n*a' and 'b' using 'print' function
    print(min([n*a, b]))

# End of the code
