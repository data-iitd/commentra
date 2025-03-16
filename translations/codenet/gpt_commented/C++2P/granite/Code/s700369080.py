
# Read the coordinates of the two points from the user
x1, y1, x2, y2 = map(int, input().split())

# Calculate the differences in x and y coordinates
dx = x2 - x1
dy = y2 - y1

# Calculate the coordinates of the two new points that form a rectangle
x3 = x2 - dy
y3 = y2 + dx
x4 = x1 - dy
y4 = y1 + dx

# Output the coordinates of the two new points
print(x3, y3, x4, y4)

