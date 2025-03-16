
# <START-OF-CODE>

# Create a BufferedReader to read input from the console
import sys

br = sys.stdin

# Read a line of input and split it into an array of strings
line = br.readline()
list = line.split(" ")

# Parse the first three elements of the input into integers
x = int(list[0])
a = int(list[1])
y = int(list[2])

# Initialize a variable to hold the result, defaulting to "NO"
h = "NO"

# Check if any of the numbers x, a, or y are either 5 or 7
if x == 5 or x == 7 or a == 5 or a == 7 or y == 5 or y == 7:
    # If the sum of x, a, and y equals 17, set the result to "YES"
    if x + y + a == 17:
        h = "YES"

# Output the result
print(h)

# 