
# Import the necessary libraries
import sys

# Define a function to read the next integer from input
def nextInt():
    return int(sys.stdin.readline().strip())

# Define a function to read the next string from input
def next():
    return sys.stdin.readline().strip()

# Define a function to check if the accumulated sum is less than h
def check(h, a):
    if h > a:
        return "No"
    else:
        return "Yes"

# Read the values of h and n from input
h, n = nextInt(), nextInt()
a = 0 # Initialize a variable to accumulate the sum of integers

# Loop to read n integers and accumulate their sum
for i in range(n):
    a += nextInt()

# Check if the accumulated sum is less than h
print(check(h, a))

