import sys; # Import the sys module for reading user input
import math; # Import the math module for mathematical operations

# Define a constant MAX for the maximum value
MAX = 100

# Read the number of points from the user input
n = int(sys.stdin.readline())

# Initialize arrays to store coordinates and heights
x = [0] * n
y = [0] * n
h = [0] * n

# Read the coordinates and heights of each point from the user input
for i in range(n):
    x[i], y[i], h[i] = map(int, sys.stdin.readline().split())

# Iterate over a range of possible coordinates (i, j) up to MAX
for i in range(MAX + 1):
    for j in range(MAX + 1):
        ch = check(n, x, y, h, i, j) # Call the check function to determine if it is a valid center
        if ch > 0: # If the check function returns a valid height
            print(i, j, ch) # Print the center coordinates and height

# Check function to determine if a point (cx, cy) is a valid center
def check(n, x, y, h, cx, cy):
    ch = -1 # Initialize ch to -1
    for i in range(n): # Loop through each point
        if h[i] > 0: # If the height of the point is greater than 0
            ch = math.fabs(x[i] - cx) + math.fabs(y[i] - cy) + h[i] # Calculate the height difference
            break # Break the loop as we found a valid height
    # Verify if the calculated height matches the height of all points
    for i in range(n):
        if h[i]!= math.max(ch - math.fabs(x[i] - cx) - math.fabs(y[i] - cy), 0):
            return -1 # If any point does not match, return -1
    return ch # Return the calculated height if all points match

# 