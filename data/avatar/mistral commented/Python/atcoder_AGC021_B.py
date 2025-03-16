# Import the math module and specifically the atan2 function and pi constant
from math import atan2, pi

# Read the input from standard input and parse it into two variables: N (number of points) and XY (a list of tuples representing the coordinates of N points)
N, * XY = map(int, open(0).read().split())

# Transpose the XY list so that it becomes a list of lists, where each inner list contains the x and y coordinates of a point
XY = list(zip(*[iter(XY)]*2))

# Iterate through each point in XY and calculate the angles between it and all other points
for i, (x, y) in enumerate(XY):
    # Calculate the differences between the x and y coordinates of the current point and all other points
    D = sorted(atan2(X[0]-x, X[1]-y) for j, X in enumerate(XY) if j != i)
    
    # Append the angle between the current point and the first point (wrapped around if it's greater than pi)
    D.append(D[0] + 2*pi)

# Initialize a variable to store the answer
ans = 0

# Iterate through each pair of consecutive angles and calculate the area of the corresponding sector
for a, b in zip(D, D[1:]):
    # If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
    if b - a >= pi:
        ans += (b - a) - pi

# Print the answer, which is the total area of the sectors divided by the total possible area (2π)
print(ans / (2 * pi))
