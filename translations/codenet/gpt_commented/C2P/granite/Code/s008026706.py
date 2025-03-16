
# Read two integer inputs from the user (representing dimensions)
a, b = map(int, input().split())

# Calculate the perimeter of the rectangle (2 * (length + width))
x = 2 * a + 2 * b

# Calculate the area of the rectangle (length * width)
y = a * b

# Output the area and perimeter
print(y, x)

# 