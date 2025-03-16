
# Python code to perform bitwise operations on two integers

# Function to print binary representation of a number
def binPrint(x, bits):
    # Iterate through each bit starting from the last one
    for i in range(bits - 1, -1, -1):
        # Print the bit value based on the bitwise AND operation with the mask (1<<i)
        print(1 if x & (1<<i) else 0, end='')
    # Print newline character after printing the binary number
    print()

# Read integer values of a and b from the standard input
a, b = map(int, input().split())

# Print binary representation of bitwise AND of a and b
binPrint(a & b, 32)

# Print binary representation of bitwise OR of a and b
binPrint(a | b, 32)

# Print binary representation of bitwise XOR of a and b
binPrint(a ^ b, 32)

# End of Python code
