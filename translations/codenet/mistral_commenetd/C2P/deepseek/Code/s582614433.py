import sys

# Data structure for an edge with source string, destination vertex, and weight
class Edge:
    def __init__(self, s, p, i):
        self.s = s
        self.p = p
        self.i = i

# Comparison function for sorting edges based on their source strings and destination vertices
def esort(a, b):
    if a.s != b.s:
        return -1 if a.s < b.s else 1
    if a.p < b.p:
        return 1
    return -1

# Read the number of vertices
n = int(input())

# Create and read edges
data = [Edge(input().strip(), int(input().strip()), i + 1) for i in range(n)]

# Sort the edges based on their source strings and destination vertices
data.sort(key=lambda edge: (edge.s, edge.p), reverse=True)

# Print the indices of the sorted edges
for edge in data:
    print(edge.i)

