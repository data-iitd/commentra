
import sys

# Create a list to store the input as a string
str = sys.stdin.readline().split()

# Create a list to store the input as integers
st = list(map(int, sys.stdin.readline().split()))

# Parse the first integer from the tokenized input
a = st[0]

# Parse the second integer from the tokenized input
b = st[1]

# Read another string from the input
u = sys.stdin.readline()

# Check if the read string is equal to the first element of the array and print accordingly
print(u.strip() == str[0], (a - 1) + " " + b) if u.strip() == str[0] else print(a + " " + (b - 1))

# End of code
