
import math

N = int(input()) # Reading the number of points
pos = [] # Initializing a list to store coordinates

# Reading coordinates of points
for _ in range(N):
    x, y = map(int, input().split()) # Reading x-coordinate and y-coordinate
    pos.append((x, y)) # Appending coordinates to the list

sum = 0 # Initializing sum to store the total distance

# Calculating the sum of distances between all pairs of points
for i in range(N):
    for j in range(N):
        if i == j: continue # Skipping the diagonal elements
        sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) # Adding distance to sum

# Calculating and printing the average distance
print(sum / N)

# Helper function to calculate the Euclidean distance between two points
def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

