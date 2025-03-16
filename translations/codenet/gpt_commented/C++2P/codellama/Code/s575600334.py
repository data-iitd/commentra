#include <iostream>
#include <cstdio>

using namespace std;

# Function to print the binary representation of an integer
def binPrint(x, bits):
  # Loop through each bit from the most significant to the least significant
  for i in range(bits - 1, -1, -1):
    # Print 1 if the ith bit is set, otherwise print 0
    print(x & (1 << i) and 1 or 0, end="")
  # Print a newline after the binary representation
  print()

# Read two unsigned integers from standard input
a, b = map(int, input().split())

# Print the binary representation of the bitwise AND of a and b
binPrint(a & b, 32)

# Print the binary representation of the bitwise OR of a and b
binPrint(a | b, 32)

# Print the binary representation of the bitwise XOR of a and b
binPrint(a ^ b, 32)

# Return 0 to indicate successful execution
return 0

