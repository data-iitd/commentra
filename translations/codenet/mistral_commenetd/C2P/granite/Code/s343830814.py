
import sys

# Read a line from standard input using input() and store it in 'buf'
buf = input()

# Calculate the length of the string read and store it in 'len'
len = len(buf)

# Print the first character of the string, its length (minus 3), and the last character of the string
print(buf[0], len-3, buf[len-2], sep='')

# End of code
