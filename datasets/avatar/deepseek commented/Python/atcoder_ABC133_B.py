import math

# Read the number of points and the dimension from the input
n, d = map(int, input().split())

# Read n points, each with d coordinates, and store them in a list called points
points = [list(map(int, input().split())) for _ in range(n)]

# Define a function to calculate the Euclidean distance between two points
def dist(x, y):
    tmp = 0.0
    for i in range(d):
        tmp += (x[i] - y[i]) ** 2
    return math.sqrt(tmp)

# Initialize a counter to keep track of pairs with integer distances
count = 0

# Iterate over all pairs of points
for i, elm in enumerate(points):
    for j in range(i + 1, n):
        # Check if the distance between the two points is an integer
        if dist(elm, points[j]).is_integer():
            count += 1

# Print the total count of pairs with integer distances
print(count)
