import sys
from collections import defaultdict

class Edge:
    def __init__(self, s, g, c):
        self.s = s  # start vertex
        self.g = g  # end vertex
        self.c = c  # cost of the edge

class Graph:
    def __init__(self):
        self.vcnt = 0  # number of vertices
        self.ecnt = 0  # number of edges
        self.e = []    # list to hold edges
        self.id = []   # list to hold index of edges for each vertex

def esort(edge):
    return (edge.s, edge.g)

def readgraph():
    g = Graph()
    n = int(sys.stdin.readline().strip())  # Read the number of vertices
    for _ in range(n - 1):
        x, y, c = map(int, sys.stdin.readline().strip().split())
        # Add edge from x to y
        g.e.append(Edge(x, y, c))
        # Add edge from y to x (undirected graph)
        g.e.append(Edge(y, x, c))
    
    g.vcnt = n  # Set vertex count
    g.ecnt = 2 * n - 2  # Set edge count (undirected edges)
    g.e.sort(key=esort)  # Sort edges based on start and end vertices

    p = 0
    g.id = [0] * (g.vcnt + 1)  # Initialize index array
    for i in range(g.vcnt):
        while p < g.ecnt and g.e[p].s < i:
            p += 1
        g.id[i] = p  # Store the index of the first edge for vertex i
    g.id[g.vcnt] = g.ecnt  # Sentinel value for the last vertex
    return g

def tyokkeidfs(g, s, tyokkeitemp):
    for i in range(g.id[s], g.id[s + 1]):
        if tyokkeitemp[g.e[i].g] == 0:  # If the vertex has not been visited
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c  # Update the distance
            tyokkeidfs(g, g.e[i].g, tyokkeitemp)  # Continue DFS

def tyokkei(g):
    tyokkeitemp = [0] * (g.vcnt + 10)  # Allocate memory for distance array
    tyokkeitemp[0] = 1  # Start DFS from vertex 0
    tyokkeidfs(g, 0, tyokkeitemp)  # First DFS to find the farthest vertex

    M = 0
    Mi = 0  # Variables to track maximum distance and corresponding vertex
    for i in range(g.vcnt):
        if tyokkeitemp[i] > M:
            M = tyokkeitemp[i]
            Mi = i

    tyokkeitemp = [0] * (g.vcnt + 10)  # Reset distances for the second DFS
    tyokkeitemp[Mi] = 1  # Start DFS from the farthest vertex found
    tyokkeidfs(g, Mi, tyokkeitemp)  # Second DFS to find the diameter

    M = max(tyokkeitemp)  # Find the maximum distance from the second DFS
    return M - 1  # Return the diameter (subtract 1 for edge count)

if __name__ == "__main__":
    g = readgraph()  # Read the graph input
    print(tyokkei(g))  # Calculate and print the diameter of the tree
