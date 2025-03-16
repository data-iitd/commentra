# Importing required packages
import sys

# Function to read a single line from stdin
def read():
    return sys.stdin.readline().strip()

# Main function
def main():
    # Reading the first integer 'a' from stdin
    a = int(read())

    # Reading the second integer 'b' from stdin
    b = int(read())

    # Calculating the sum of 'a' and 'b'
    ret = a + b

    # Checking if the sum is less than the difference of 'a' and 'b'
    if ret < (a - b):
        # If true, then update the value of 'ret'
        ret = a - b

    # Checking if the sum is less than the product of 'a' and 'b'
    if ret < (a * b):
        # If true, then update the value of 'ret'
        ret = a * b

    # Printing the final value of 'ret'
    print(ret)

# End of the code