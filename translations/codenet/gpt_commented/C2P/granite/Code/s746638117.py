
# Read the length and width from user input
a, b = map(int, input().split())

# Calculate the area of the rectangle (length * width)
ar = a * b

# Calculate the perimeter of the rectangle (2 * (length + width))
le = 2 * (a + b)

# Output the calculated area and perimeter
print(ar, le)

# 