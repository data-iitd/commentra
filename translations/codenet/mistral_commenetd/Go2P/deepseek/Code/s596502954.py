import sys
import re

# Function to read a single word as a string from the input
def next():
    return sys.stdin.readline().strip()

# Function to read an integer from the input
def next_int():
    return int(next())

# Function to read a float64 from the input
def next_float64():
    return float(next())

# Function to read n integers from the input and return as a list
def next_ints(n):
    return [next_int() for _ in range(n)]

# Main function
def main():
    # Read the first three integers from the input
    a, b, c = next_ints(3)

    # Check if the condition is true
    if a + b >= c:
        # If true, print "Yes" to the output
        print("Yes")
    else:
        # If false, print "No" to the output
        print("No")

# Set the input to read words instead of lines
sys.stdin.readline = lambda: next()

# Call the main function
main()

