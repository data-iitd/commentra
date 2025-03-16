import sys
import math
import random

# Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# Define an infinite value for comparison
inf = math.inf

# Initialize random seed
random.seed()

# Function to read input
def read_input():
    return sys.stdin.read().strip()

# Main function where the program execution starts
def main():
    N = read_input()  # Read input as a string
    n = sum(int(digit) for digit in N)  # Calculate the sum of digits

    # Convert the string input to an integer
    m = int(N)
    # Check if the number is divisible by the sum of its digits
    if m % n == 0:
        print("Yes")  # Print "Yes" if divisible
    else:
        print("No")  # Print "No" if not divisible

# Utility functions for various operations

# Check if a value is within a range
def in_range(c, a, z):
    return a <= c < z

# Check if a value is outside a range
def out_range(c, a, z):
    return not in_range(c, a, z)

# Convert boolean to integer (1 for true, 0 for false)
def btoi(b):
    return 1 if b else 0

# Convert integer to boolean (non-zero to true, zero to false)
def itob(a):
    return a != 0

# Return the maximum value from a list of integers
def max_value(*args):
    return max(args)

# Return the minimum value from a list of integers
def min_value(*args):
    return min(args)

# Calculate the sum of a list of integers
def sum_values(a):
    return sum(a)

# Calculate the product of a list of integers
def product(a):
    result = 1
    for num in a:
        result *= num
    return result

# Fill a list with a specified value
def fill(a, n):
    return [n] * len(a)

# Return the minimum and maximum of two integers
def minmax(a, b):
    return (min(a, b), max(a, b))

# Return the absolute value of an integer
def abs_value(a):
    return abs(a)

# Calculate the ceiling of a division of two integers
def ceil_div(a, b):
    return (a + b - 1) // b if b != 0 else 0

# Print a list of strings with space separation
def print_strings(out):
    print(" ".join(out))

# Print a list of integers with space separation
def print_ints(out):
    print(" ".join(map(str, out)))

# Entry point
if __name__ == "__main__":
    main()

# <END-OF-CODE>
