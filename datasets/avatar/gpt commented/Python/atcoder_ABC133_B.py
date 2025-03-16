import math

# Read the number of points (n) and the dimension (d) from input
n, d = map(int, input().split())

# Read the coordinates of the points into a list
points = [list(map(int, input().split())) for _ in range(n)]

# Define a function to calculate the Euclidean distance between two points
def dist(x, y):
    tmp = 0.0
    # Calculate the squared differences for each dimension
    for i in range(d):
        tmp += (x[i] - y[i]) ** 2
    # Return the square root of the sum of squared differences
    return math.sqrt(tmp)

# Initialize a counter for pairs of points with integer distances
count = 0

# Iterate through each point and compare it with every other point
for i, elm in enumerate(points):
    for j in range(i + 1, n):
        # Check if the distance between the two points is an integer
        if dist(elm, points[j]).is_integer():
            count += 1  # Increment the count if the distance is an integer

# Print the total count of pairs with integer distances
print(count)
