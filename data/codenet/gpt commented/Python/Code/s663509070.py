# Read the dimensions N (number of points) and D (dimension of each point)
N, D = map(int, input().split())

# Initialize an empty list to store the points
mat = []

# Read N points from input and store them in the list 'mat'
for d in range(N):
    mat.append([int(x) for x in input().split()])

# Import the math module to use the square root function
import math

# Initialize a counter to keep track of pairs with integer distances
c = 0

# Iterate through each unique pair of points in 'mat'
for i in range(len(mat) - 1):
    for j in range(i + 1, len(mat)):
        # Calculate the Euclidean distance between the two points
        dist = math.sqrt(sum([(x - y) ** 2 for x, y in zip(mat[i], mat[j])]))
        
        # Check if the distance is an integer
        if int(dist) == dist:
            # Increment the counter if the distance is an integer
            c += 1

# Print the total count of pairs with integer distances
print(c)
