from collections import defaultdict
import sys

# Read the number of vertices from the input
n = int(input().strip())

# Initialize an answer vector of size n
ans = [0] * n

# Read the edges and increment the count of each vertex in the answer vector
for _ in range(n - 1):
    a = int(input().strip())
    a -= 1  # Decrement the vertex index as it is 0-indexed
    ans[a] += 1  # Increment the count of the vertex

# Print the answer vector
for i in range(n):
    print(ans[i])

# End-of-code
