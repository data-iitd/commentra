
# Python 3.6.2
# Author: <NAME>
# Date: 2018-02-12

# This is a simple program to convert a decimal number to its binary representation

# Input:
# A single integer

# Output:
# The binary representation of the input number

# Note:
# The input number must be non-negative

# Function to compute the greatest common divisor (GCD) using recursion
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Function to convert a decimal number to its binary representation
def to_binary(n):
    # Special case: if the input number is 0, output '0' and exit
    if n == 0:
        return '0'

    # Initialize an empty string to hold the binary representation
    s = ''

    # Loop to convert the number to its binary representation in a specific format
    i = 1
    while n!= 0:
        # Check if the current number is even or odd
        if n % 2 == 0:
            s += '0' # Append '0' for even numbers
        else:
            s += '1' # Append '1' for odd numbers

        # Adjust the number for the next iteration
        n -= abs(n % 2) # Reduce n by 1 if it's odd
        n /= -2 # Divide n by -2 to continue the conversion

    # Reverse the string to get the correct binary representation
    return s[::-1]

# Main function
if __name__ == '__main__':
    n = int(input()) # Read an integer from standard input

    # Output the final binary string
    print(to_binary(n))

