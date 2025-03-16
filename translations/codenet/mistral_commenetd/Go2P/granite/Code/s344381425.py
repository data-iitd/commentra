
# Import the "sys" module for standard input/output
import sys

# Read three integer values from the standard input using the input function
# and store them in variables "a", "b", and "c"
a, b, c = map(int, sys.stdin.read().split())

# Check if the condition "a < b and b < c" is true using an if statement
if a < b and b < c:
    # If the condition is true, print the string "Yes" to the standard output
    print("Yes")
else:
    # If the condition is false, print the string "No" to the standard output
    print("No")

# End of code