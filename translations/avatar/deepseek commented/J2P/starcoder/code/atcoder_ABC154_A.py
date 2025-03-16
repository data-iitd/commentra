
import sys

# Read the first line of input, split by spaces, and store in an array of strings
str = sys.stdin.readline().split()

# Create a StringTokenizer to parse the next line of input as integers
st = sys.stdin.readline().split()

# Parse the first integer from the tokenized input
a = int(st[0])

# Parse the second integer from the tokenized input
b = int(st[1])

# Read another string from the input
u = sys.stdin.readline()

# Check if the read string is equal to the first element of the array and print accordingly
print(u == str[0] and (a - 1) + " " + b or a + " " + (b - 1))

# 