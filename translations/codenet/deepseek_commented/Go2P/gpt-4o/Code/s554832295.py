# Declare variables to store the coordinates
x1, y1, x2, y2 = map(int, input().split())

# Calculate the differences between the coordinates
a = x2 - x1
b = y2 - y1

# Calculate the new coordinates based on the differences
x3 = x2 - b
y3 = y2 + a
x4 = x1 - b
y4 = y1 + a

# Print the new coordinates to standard output
print(x3, y3, x4, y4)

# <END-OF-CODE>
