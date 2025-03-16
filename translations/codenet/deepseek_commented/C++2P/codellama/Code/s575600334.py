#include <iostream>
#include <cstdio>

using namespace std;

# Function to print the binary representation of an integer x with a specified number of bits
def binPrint(x, bits):
  for i in range(bits-1, -1, -1):
    print((x&(1<<i))>>i, end='')
  print()

a,b = map(int, input().split())  # Read two unsigned integers from standard input

binPrint(a&b, 32)  # Print the binary AND of a and b
binPrint(a|b, 32)  # Print the binary OR of a and b
binPrint(a^b, 32)  # Print the binary XOR of a and b

# 