
# Python program to solve the problem

# Import the Scanner class for reading input
from sys import stdin

# Read the number of test cases from the standard input
t = int(stdin.readline())

# Initialize a counter variable to keep track of the number of valid cases
count = 0

# Read the number of test cases and process each one in the while loop
while t > 0:
    # Read the first integer from the standard input
    a = int(stdin.readline())

    # Read the second integer from the standard input
    b = int(stdin.readline())

    # Read the third integer from the standard input
    c = int(stdin.readline())

    # Check if any of the given integers are equal to 1. If so, increment the counter.
    if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
        count += 1  # Increment the counter if any of the given integers are equal to 1

    # Decrement the counter variable by 1
    t -= 1

# Print the value of the counter to the standard output
print(count)

