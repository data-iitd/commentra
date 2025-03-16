# Importing the math module for calculating the square root
import math

# Taking the number of points, n, and the number of dimensions, d, as input
n, d = map(int, input().split())

# Initializing a list 'points' of size 'n' to store the coordinates of each point
points = [list(map(int, input().split())) for _ in range(n)]

# Defining a function 'dist' to calculate the Euclidean distance between two points
def dist(x, y):
    # Initializing a variable 'tmp' to store the sum of squared differences between corresponding elements of 'x' and 'y'
    tmp = 0.0

    # Iterating through each dimension 'i' from 0 to 'd'
    for i in range(d):
        # Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
        tmp += (x[i] - y[i]) ** 2

    # Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
    return math.sqrt(tmp)

# Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
count = 0

# Iterating through each point 'i' in 'points'
for i, elm in enumerate(points):
    # Iterating through each point 'j' from 'i+1' to the last point in 'points'
    for j in range(i+1, n):
        # Checking if the Euclidean distance between 'elm' and 'points[j]' is an integer
        if dist(elm, points[j]).is_integer():
            # Incrementing the 'count' variable if the condition is true
            count += 1

# Printing the final value of 'count'
print(count)
