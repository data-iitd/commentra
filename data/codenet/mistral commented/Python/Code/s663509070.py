
# Read the number of nodes N and the number of dimensions D from user input
N, D = map(int, input().split())

# Initialize an empty list called mat to store the coordinates of N nodes
mat = []

# Read the coordinates of each node from user input and append it as a list to the mat list
for d in range(N):
    row = list(map(int, input().split()))
    mat.append(row)

# Import the math module which contains the sqrt() function used to calculate the Euclidean distance
import math

# Initialize a counter variable c to keep track of the number of nodes on the same circle
c = 0

# Compare each pair of nodes (i,j) where i < j
for i in range(len(mat)-1):
    for j in range(i+1, len(mat)):
        # Calculate the Euclidean distance between nodes i and j
        dist = math.sqrt(sum([(x-y)**2 for x,y in zip(mat[i], mat[j])]))

        # If the distance is an integer and equal to its square root, it means that the two nodes are on the same circle
        if int(dist) == dist:
            # Increment the counter variable c by one
            c += 1

# Print the value of c to the console
print(c)