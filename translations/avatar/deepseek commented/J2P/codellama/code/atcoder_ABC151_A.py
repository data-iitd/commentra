
import sys

# Create a BufferedReader to read input from the console
r = sys.stdin

# Read a single line of input from the user
s = r.readline()

# Increment the first character of the input by 1 and print it
print(chr(ord(s[0]) + 1))

# END-OF-CODE
