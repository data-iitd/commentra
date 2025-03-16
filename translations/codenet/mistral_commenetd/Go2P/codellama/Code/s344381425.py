# Import the "sys" module for reading input from the standard input
import sys

# Read the three integer values "a", "b", and "c" from the standard input
a, b, c = map(int, sys.stdin.readline().split())

# Check if the condition "a < b < c" is true using an if statement
if a < b < c:
    # If the condition is true, print the string "Yes" to the standard output
    print("Yes")
else:
    # If the condition is false, print the string "No" to the standard output
    print("No")

# End of code
