
import math

# Read the number of vectors (N) and their dimensionality (D)
N, D = map(int, input().split())

# Initialize a 2D array to store the vectors
vectors = []
for _ in range(N):
    vectors.append(list(map(int, input().split())))

# Initialize a counter for the number of pairs with integer distances
answer = 0

# Calculate the pairwise distances between all vectors
for i in range(N - 1):
    for j in range(i + 1, N):
        dist = 0

        # Calculate the squared distance between vector i and vector j
        for d in range(D):
            x = vectors[i][d] - vectors[j][d]
            dist += x * x

        # Calculate the Euclidean distance
        sq = math.sqrt(dist)

        # Check if the distance is an integer (within a small epsilon)
        answer += 1 if abs(sq - math.floor(sq)) < 0.001 else 0

# Output the total count of pairs with integer distances
print(answer)
