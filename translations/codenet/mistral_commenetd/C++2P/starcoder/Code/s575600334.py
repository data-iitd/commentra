# Python 3 program to print binary
# representation of bitwise AND, OR and XOR

# Function to print binary representation of a number
def binPrint(x, bits):

  # Iterate through each bit starting from the last one
  for i in range(bits - 1, -1, -1):

    # Print the bit value based on the bitwise AND operation with the mask (1<<i)
    print(x & (1 << i)? 1 : 0, end = '')

  # Print newline character after printing the binary number
  print()

# Driver Code
if __name__ == '__main__':

  # Declare unsigned integer variables a and b
  a, b = 10, 15

  # Print binary representation of bitwise AND of a and b
  binPrint(a & b, 32)

  # Print binary representation of bitwise OR of a and b
  binPrint(a | b, 32)

  # Print binary representation of bitwise XOR of a and b
  binPrint(a ^ b, 32)

# 