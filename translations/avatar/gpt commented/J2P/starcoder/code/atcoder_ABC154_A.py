
# <START-OF-CODE>

# Create a BufferedReader to read input from the standard input stream
in = sys.stdin

# Read a line of input, split it by spaces, and store it in an array
str = in.readline().split(" ")

# Create a StringTokenizer to read the next line of input
st = in.readline().split()

# Parse the first token as an integer and store it in variable 'a'
a = int(st[0])

# Parse the second token as an integer and store it in variable 'b'
b = int(st[1])

# Read another line of input and store it in variable 'u'
u = in.readline()

# Compare the string 'u' with the first element of the array'str'
# Print the result based on the comparison
print(u == str[0] and (a - 1) + " " + b or a + " " + (b - 1))

# 