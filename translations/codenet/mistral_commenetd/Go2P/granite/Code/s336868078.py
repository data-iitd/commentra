
# Importing required packages
import sys

# Function to find the solution
def solve(a, b, c):
    # Declaring a temporary variable
    temp_ = 0

    # Checking if c is equal to the sum of a and b
    if c == a + b:
        # If true, then calculate the value of temp_
        temp_ = b + c
        # Add a comment explaining the logic
        # temp_ = b + c; # c is equal to the sum of a and b
    elif c - 1 > a + b:
        # Else if c is greater than the sum of a and b by 1
        # Calculate the difference between c and the sum of a and b
        temp = c - (a + b)
        # Calculate the value of temp_
        temp_ = b + c - temp
        # Add a comment explaining the logic
        # temp_ = b + c - (c - (a + b)); # c is greater than the sum of a and b by 1
    else:
        # Else, c is less than or equal to the sum of a and b
        # Calculate the value of temp_
        temp_ = b + c
        # Add a comment explaining the logic
        # temp_ = b + c; # c is less than or equal to the sum of a and b

    # Return the value of temp_ as the answer
    return temp_

# Main function to read input and call the solve function
def main():
    # Declaring variables a, b, and c to read input
    a, b, c = map(int, sys.stdin.readline().split())
    # Calling the solve function and storing the result in ans
    ans = solve(a, b, c)
    # Printing the answer using print
    print(ans)
    # Add a comment explaining the logic
    # ans = solve(a, b, c); # Solving the problem using the solve function

# End of the code