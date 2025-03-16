
import sys

# Read a line of input, split it by spaces, and store it in a list
str = input().split()

# Read the next line of input and split it by spaces, storing the tokens in a list
st = input().split()

# Parse the first token as an integer and store it in variable 'a'
a = int(st[0])

# Parse the second token as an integer and store it in variable 'b'
b = int(st[1])

# Read another line of input and store it in variable 'u'
u = input()

# Compare the string 'u' with the first element of the list'str'
# Print the result based on the comparison
print(u == str[0] and a - 1 or a, b - 1 if u!= str[0] else b)

