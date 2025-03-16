# Import the sys module to read from standard input
import sys

# Read a line of input from standard input (stdin)
buf = sys.stdin.readline()

# Calculate the length of the input string
length = len(buf)

# Print the first character, the length of the string minus 3, and the second to last character
print(f"{buf[0]}{length - 3}{buf[length - 2]}")

# End of the code
# <END-OF-CODE>
