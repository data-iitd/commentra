import sys

# Read the coordinates of the two points (x1, y1) and (x2, y2)
x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

# Check if the two points are vertically aligned (same x-coordinate)
if x1 == x2:
    # Calculate the vertical distance between the two points
    dif = abs(y1 - y2)
    # Output the coordinates of the rectangle formed by the two points
    print((x1 + dif) + " " + y1 + " " + (x1 + dif) + " " + y2)
# Check if the two points are horizontally aligned (same y-coordinate)
elif y1 == y2:
    # Calculate the horizontal distance between the two points
    dif = abs(x1 - x2)
    # Output the coordinates of the rectangle formed by the two points
    print((x1) + " " + (y1 + dif) + " " + (x2) + " " + (y2 + dif))
# Check if the two points form a square (equal distance in both x and y)
elif abs(x1 - x2) == abs(y1 - y2):
    # Output the coordinates of the rectangle formed by swapping y-coordinates
    print(x1 + " " + y2 + " " + x2 + " " + y1)
# If none of the above conditions are met, output -1 indicating no rectangle can be formed
else:
    print(-1)

# 