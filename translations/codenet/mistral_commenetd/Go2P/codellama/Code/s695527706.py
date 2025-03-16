
# Import the "sys" module
import sys

# Import the "string" module
import string

# Read the input from the standard input
n, s = map(int, input().split())

# Call the string.count function to count the number of occurrences of "ABC" in the string s
# Print the result using the print function
print(string.count(s, "ABC"))

# This is the end of the code
