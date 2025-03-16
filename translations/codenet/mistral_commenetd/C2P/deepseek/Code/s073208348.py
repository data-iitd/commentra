import sys
from collections import defaultdict

# Define the structure for the edge and graph.
class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

class Graph:
    def __init__(self):
        self.vcnt = 0
        self.ecnt = 0
        self.edges = []
        self.id = defaultdict(int)

# Read the graph from the standard input.
def readgraph():
    # Read the number of vertices.
    n = int(sys.stdin.readline().strip())
    # Allocate memory for the vertices and edges.
    g.vcnt = n
    g.ecnt = 2 * n - 2
    # Allocate memory for the edge array and sort it.
    g.edges = [Edge(0, 0, 0) for _ in range(g.ecnt)]
    for i in range(n - 1):
        x, y, c = map(int, sys.stdin.readline().strip().split())
        # Add an edge from x to y and y to x with the given cost.
        g.edges[i].s = x
        g.edges[i].g = y
        g.edges[i].c = c
        g.edges[i + g.ecnt].s = y
        g.edges[i + g.ecnt].g = x
        g.edges[i + g.ecnt].c = c
    # Set the number of edges.
    g.ecnt *= 2
    # Sort the edges using sorted.
    g.edges.sort(key=lambda edge: (edge.s, edge.g))
    # Initialize the id array.
    p = 0
    for i in range(g.vcnt):
        # Find the index of the current vertex in the sorted edge list.
        while p < g.ecnt and g.edges[p].s < i:
            p += 1
        g.id[i] = p
    # Set the last index as a sentinel.
    g.id[g.vcnt] = g.ecnt

# Function to find the diameter of the tree using DFS algorithm.
def tyokkeidfs(s, depth):
    # Iterate through the edges connected to the current vertex.
    for i in range(g.id[s], g.id[s + 1]):
        # If the destination vertex has not been visited yet, recursively call tyokkeidfs.
        if not visited[g.edges[i].g]:
            visited[g.edges[i].g] = True
            tyokkeidfs(g.edges[i].g, depth + g.edges[i].c)

def tyokkei():
    global visited
    # Allocate memory for visited array.
    visited = [False] * g.vcnt
    # Initialize the root vertex depth to 1.
    visited[0] = True
    # Perform DFS from the root vertex.
    tyokkeidfs(0, 0)
    # Find the maximum depth.
    M = 0
    Mi = 0
    for i in range(g.vcnt):
        # If the current vertex depth is greater than the maximum depth, update it.
        if depth[i] > M:
            M = depth[i]
            Mi = i
    # Return the diameter which is the maximum depth minus 1.
    return M - 1

# Main function to read the graph and print the diameter.
if __name__ == "__main__":
    # Initialize the graph structure.
    g = Graph()
    # Read the graph.
    readgraph()
    # Call the tyokkei function to find the diameter.
    print(tyokkei())
