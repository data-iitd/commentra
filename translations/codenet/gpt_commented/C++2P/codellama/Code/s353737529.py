
# これを入れて実行
# python code.py

# Import the required libraries
import sys

# Function to convert a number to its binary representation
def convert_to_binary(n):
    # Initialize an empty string to hold the binary representation
    s = ""

    # Special case: if the input number is 0, output '0' and exit
    if n == 0:
        return "0"

    # Loop to convert the number to its binary representation in a specific format
    i = 1
    while n != 0:
        # Check if the current number is even or odd
        if n % 2 == 0:
            s += "0"  # Append '0' for even numbers
        else:
            s += "1"  # Append '1' for odd numbers

        # Adjust the number for the next iteration
        n -= abs(n % 2)  # Reduce n by 1 if it's odd
        n /= -2  # Divide n by -2 to continue the conversion

    # Reverse the string to get the correct binary representation
    s = s[::-1]

    # Output the final binary string
    return s


# Read an integer from standard input
n = int(sys.stdin.readline().strip())

# Convert the number to its binary representation
s = convert_to_binary(n)

# Output the final binary string
print(s)

