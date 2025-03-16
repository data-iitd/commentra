import sys

# Define a constant for the maximum coordinate value
MAX = 100

# Read the number of points
n = int(input())

# Initialize arrays to store x, y coordinates and heights
x = [0] * n
y = [0] * n
h = [0] * n

# Read the x, y coordinates and heights for each point
for i in range(n):
    x[i], y[i], h[i] = map(int, input().split())

# Iterate through all possible coordinates (i, j) within the defined range
for i in range(MAX + 1):
    for j in range(MAX + 1):
        # Check the height at the current coordinate (i, j)
        ch = check(n, x, y, h, i, j)
        # If the height is valid (greater than 0), print the coordinates and height
        if ch > 0:
            print(i, j, ch)

# Method to check the height at a given coordinate (cx, cy)
def check(n, x, y, h, cx, cy):
    ch = -1

    # Calculate the initial height based on the first point with a positive height
    for i in range(n):
        if h[i] > 0:
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]
            break

    # Validate the height against all points
    for i in range(n):
        # If the calculated height does not match the expected height, return -1
        if h[i]!= max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):
            return -1

    # Return the calculated height if all checks pass
    return ch

# 