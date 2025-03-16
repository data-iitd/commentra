
# Import the required libraries
import sys

# Create a buffered reader to read input from standard input
in = sys.stdin.readline

# Function to solve the problem based on the given parameters a, b, and c
def solve(a, b, c):
    # Check if c is equal to the sum of a and b
    if c == a+b:
        # If true, calculate the result as b + c
        temp = b + c
    elif c-1 > a+b:
        # If c-1 is greater than the sum of a and b, calculate the difference
        temp = (c - 1) - (a + b)
        # Adjust the result based on the calculated difference
        temp = b + c - temp
    else:
        # If neither condition is met, simply return b + c
        temp = b + c
    # Return the calculated result
    return temp

# Read three integers from standard input
a, b, c = map(int, in().split())

# Call the solve function with the input values and store the result
ans = solve(a, b, c)

# Print the result to standard output
print(ans)

