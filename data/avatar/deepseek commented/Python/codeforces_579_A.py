
import math
# Take an integer input from the user
n = int(input())
# Initialize a variable x to 1
x = 1
# Continue looping until the base-2 logarithm of n is an integer
while math.log2(n) % 1:
    # Increment x by 1
    x += 1
    # Update n by subtracting 2 raised to the power of the integer part of the base-2 logarithm of n
    n -= 2 ** (int(math.log2(n)))
# Print the value of x
print(x)


