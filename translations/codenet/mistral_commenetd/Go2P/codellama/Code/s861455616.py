
# Import the "sys" module for reading input from the standard input
import sys

# Read a string input from the standard input
s = sys.stdin.readline().strip()

# Check if the length of the string "s" is greater than or equal to 4
# and if its first four characters are "YAKI"
if len(s) >= 4 and s[:4] == "YAKI":
    # If the condition is true, print the word "Yes" to the standard output
    print("Yes")
else:
    # If the condition is false, print the word "No" to the standard output
    print("No")

# End of code
