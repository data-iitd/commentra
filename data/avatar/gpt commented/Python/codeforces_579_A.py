import math  # Import the math module to use mathematical functions

# Read an integer input from the user
n = int(input())

# Initialize a counter variable to track the number of iterations
x = 1

# Continue looping while n is not a power of 2
while math.log2(n) % 1:
    x += 1  # Increment the counter for each iteration
    # Subtract the largest power of 2 less than or equal to n from n
    n -= 2 ** (int(math.log2(n)))

# Print the final count of iterations
print(x)
