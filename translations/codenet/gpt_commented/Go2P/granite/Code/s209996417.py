
import math

# Read input values for n and k from the user
n = float(input())
k = float(input())

# Determine the number of digits when n is represented in base k
# Example: For n = 10 in base 2, it is represented as 1010 which has 4 digits
# The number of digits is determined by the highest power of k that is less than or equal to n.
# In this case, we need to find x such that k^x <= n < k^(x+1)
# The result will be x + 1, which gives the total number of digits.

x = 0.0  # Initialize x to 0, which represents the current power of k being evaluated
while True:
    # Calculate k raised to the power of x (lower bound)
    under = math.pow(k, x)
    # Calculate k raised to the power of x + 1 (upper bound)
    upper = math.pow(k, x + 1)

    # Check if n falls within the range [k^x, k^(x+1))
    if under <= n and n < upper:
        # If it does, print the number of digits (which is x + 1) and exit the program
        print(x + 1)
        break
    # Increment x to check the next power of k
    x += 1

