
import sys

# Read the number of vertices (or nodes)
n = int(input())

# Initialize a list to store the count of edges for each vertex
ans = [0] * n

# Read n-1 edges and count the occurrences for each vertex
for _ in range(n - 1):
    a = int(input()) - 1  # Read the vertex index and convert to 0-based index
    ans[a] += 1  # Increment the count for the corresponding vertex

# Output the count of edges for each vertex
for i in range(n):
    print(ans[i])  # Print the count for vertex i

