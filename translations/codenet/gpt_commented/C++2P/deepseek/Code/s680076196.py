# Read four integer values from standard input
a, b, c, d = map(int, input().split())

# Calculate the product of the differences between the first two and the last two integers
# This represents the area of a rectangle defined by the points (a, b) and (c, d)
area = (a - c) * (b - d)

# Print the calculated area
print(area)
