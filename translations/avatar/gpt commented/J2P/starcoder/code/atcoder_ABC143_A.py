
# <START-OF-CODE>

# Create a Scanner object to read input from the console
s = Scanner(sys.stdin)

# Read a line of input, trim whitespace, and split it into an array of strings
x = s.nextLine().strip().split(" ")

# Parse the first and second elements of the array as integers
a = int(x[0])
b = int(x[1])

# Calculate the value of c based on the formula: c = a - b * 2
c = a - b * 2

# If c is negative, set it to 0
if c < 0:
    c = 0

# Output the final value of c
print(c)

# 