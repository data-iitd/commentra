
import sys

# Read the number of vertices
n = int(input())

# Read edges and construct the graph
edges = []
for _ in range(n - 1):
    x, y, c = map(int, input().split())
    edges.append((x, y, c))

# Sort edges based on start and end vertices
edges.sort(key=lambda x: (x[0], x[1]))

# Create an index for edges for each vertex
index = [0] * (n + 1)
p = 0
for i in range(n):
    while p < len(edges) and edges[p][0] < i:
        p += 1
    index[i] = p
index[n] = len(edges)

# Function to perform DFS and find the diameter of the tree
def tyokkeidfs(s):
    distances = [0] * (n + 10)
    distances[s] = 1
    for i in range(index[s], index[s + 1]):
        if distances[edges[i][1]] == 0:
            distances[edges[i][1]] = distances[s] + edges[i][2]
            tyokkeidfs(edges[i][1])
    return distances

# Calculate the diameter of the tree
distances = tyokkeidfs(0)
M = max(distances)
Mi = distances.index(M)
distances = tyokkeidfs(Mi)
M = max(distances)
print(M - 1) # Print the diameter (subtract 1 for edge count)

Translate the above Python code to Java and end with comment "