
import sys

# Read a line of input from standard input (stdin)
buf = sys.stdin.readline()

# Calculate the length of the input string
len = len(buf)

# Print the first character, the length of the string minus 3, and the second to last character
print(buf[0], len-3, buf[len-2], sep="")

# End of code
