# Read a line of input from standard input (stdin) into the buffer
buf = raw_input()

# Calculate the length of the input string
len = len(buf)

# Print the first character, the length of the string minus 3, and the second to last character
print buf[0], len-3, buf[len-2]

# Return 0 to indicate successful completion of the program
0

