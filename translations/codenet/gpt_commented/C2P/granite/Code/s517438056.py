
import math

# Read the number of vectors (N) and their dimensions (D) from user input
N, D = map(int, input().split())

# Create a 2D list (matrix) to hold N vectors of D dimensions
matrix = [list(map(int, input().split())) for _ in range(N)]

# Initialize a variable (k) to count the pairs of vectors with integer distances
k = 0

# Calculate the pairwise distances between all vectors
for i in range(N - 1):
    for j in range(i + 1, N):
        m = 0  # Variable to accumulate the squared differences
        # Calculate the squared distance between vector i and vector j
        for n in range(D):
            m = (matrix[i][n] - matrix[j][n]) ** 2 + m
        # Calculate the Euclidean distance
        l = math.sqrt(m)
        # Check if the distance is an integer (i.e., if its ceiling equals its floor)
        if math.ceil(l) == math.floor(l):
            k += 1

# Output the count of pairs of vectors with integer distances
print(k)

