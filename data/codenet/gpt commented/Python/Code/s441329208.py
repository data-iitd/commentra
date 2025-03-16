import sys  # Import the sys module to access system-specific parameters and functions

# Set up input reading functions for efficiency
read = sys.stdin.read  # Function to read all input at once
readline = sys.stdin.readline  # Function to read a single line of input
readlines = sys.stdin.readlines  # Function to read multiple lines of input

# Increase the recursion limit to handle deep recursion if necessary
sys.setrecursionlimit(10 ** 7)

# Read a line of input, strip whitespace, and sort the characters in ascending order
s = sorted(readline().rstrip())

# Read another line of input, strip whitespace, sort the characters in ascending order, and then reverse the order
t = sorted(readline().rstrip())[::-1]

# Compare the sorted version of the first string with the reversed sorted version of the second string
# Print "Yes" if the first string is lexicographically less than the second, otherwise print "No"
print("Yes" if s < t else "No")
