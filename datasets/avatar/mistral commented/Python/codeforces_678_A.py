
# Import the map function from the built-in module
# Read a line of text from the standard input stream and convert it into a list of integers
vamshi, z = map(int, input().split())

# Calculate the number of complete divisions of z into vamshi
# Add 1 to account for the remainder
# Multiply the result by z
print((vamshi // z + 1) * z)