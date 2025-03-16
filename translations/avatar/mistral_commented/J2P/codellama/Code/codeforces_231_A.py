import sys

# Read the number of test cases from the standard input
t = int(sys.stdin.readline())

# Initialize a counter variable to keep track of the number of valid cases
count = 0

# Read the number of test cases and process each one in the while loop
while t > 0:
    # Read the three integers from the standard input
    a, b, c = map(int, sys.stdin.readline().split())

    # Check if any of the given integers are equal to 1. If so, increment the counter.
    if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
        count += 1  # Increment the counter if any of the given integers are equal to 1

    t -= 1  # Decrement the number of test cases

# Print the value of the counter to the standard output
print(count)

