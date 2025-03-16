# Read three integers from user input and unpack them into variables a, b, and c
a, b, c = map(int, input().split())

# Calculate the area of a triangle using the formula (base * height) / 2
# Here, we assume 'a' is the base and 'b' is the height
area = int((a * b) / 2)

# Print the calculated area of the triangle
print(area)
