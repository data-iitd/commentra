
import sys

# Function to print the binary representation of an integer x with a specified number of bits
def binPrint(x, bits):
    for i in range(bits-1, -1, -1):
        sys.stdout.write(str(x & (1 << i)))
    sys.stdout.write('\n')

# Read two unsigned integers from standard input
a = int(input())
b = int(input())

binPrint(a & b, 32)  # Print the binary AND of a and b
binPrint(a | b, 32)  # Print the binary OR of a and b
binPrint(a ^ b, 32)  # Print the binary XOR of a and b

