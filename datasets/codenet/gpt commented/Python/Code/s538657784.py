import math  # Import the math module to use mathematical functions

# Read an integer input from the user
N = int(input())

# Calculate the integer square root of N
sqN = int(math.sqrt(N))

# Iterate from 0 to the integer square root of N
for i in range(sqN):
    # Check if the current value (sqN - i) is a divisor of N
    if N % (sqN - i) == 0:
        # If it is a divisor, calculate and print the result based on the formula
        print(int(N / (sqN - i) + sqN - i) - 2)
        break  # Exit the loop after finding the first divisor
