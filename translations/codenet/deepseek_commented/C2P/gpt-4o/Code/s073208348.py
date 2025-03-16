import sys
from collections import defaultdict

class Edge:
    def __init__(self, s, g, c):
        self.s = s
        self.g = g
        self.c = c

class Graph:
    def __init__(self):
        self.vcnt = 0
        self.ecnt = 0
        self.e = []
        self.id = []

def read_graph():
    g = Graph()
    n = int(sys.stdin.readline().strip())  # Read the number of vertices
    for _ in range(n - 1):  # Read each edge and store it in the graph structure
        x, y, c = map(int, sys.stdin.readline().strip().split())
        g.e.append(Edge(x, y, c))
        g.e.append(Edge(y, x, c))
    g.vcnt = n  # Set the number of vertices
    g.ecnt = 2 * n - 2  # Set the number of edges
    g.e.sort(key=lambda edge: (edge.s, edge.g))  # Sort the edges

    p = 0
    g.id = [0] * (g.vcnt + 1)
    for i in range(g.vcnt):  # Populate the id array with the starting index of edges for each vertex
        while p < g.ecnt and g.e[p].s < i:
            p += 1
        g.id[i] = p
    g.id[g.vcnt] = g.ecnt  # Set the sentinel value for the id array
    return g

def dfs(g, s, tyokkeitemp):
    for i in range(g.id[s], g.id[s + 1]):
        if tyokkeitemp[g.e[i].g] == 0:
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
            dfs(g, g.e[i].g, tyokkeitemp)

def find_diameter(g):
    tyokkeitemp = [0] * (g.vcnt + 10)  # Allocate memory for the temporary array
    tyokkeitemp[0] = 1  # Start DFS from the root
    dfs(g, 0, tyokkeitemp)  # Perform DFS

    M = 0
    Mi = 0
    for i in range(g.vcnt):  # Find the vertex with the maximum distance from the root
        if tyokkeitemp[i] > M:
            M = tyokkeitemp[i]
            Mi = i

    tyokkeitemp = [0] * (g.vcnt + 10)  # Reset the temporary array
    tyokkeitemp[Mi] = 1  # Start DFS from the farthest vertex found
    dfs(g, Mi, tyokkeitemp)  # Perform DFS

    M = max(tyokkeitemp)  # Find the maximum distance in the second DFS
    return M - 1  # Return the diameter of the tree

def main():
    g = read_graph()  # Read the graph
    print(find_diameter(g))  # Print the diameter of the tree

if __name__ == "__main__":
    main()

# <END-OF-CODE>
