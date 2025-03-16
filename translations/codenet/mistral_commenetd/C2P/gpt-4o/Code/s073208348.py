# This is a Python code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.

class Edge:
    def __init__(self, s, g, c):
        self.s = s  # Source vertex
        self.g = g  # Destination vertex
        self.c = c  # Cost

class Graph:
    def __init__(self, n):
        self.vcnt = n  # Number of vertices
        self.ecnt = 2 * n - 2  # Number of edges
        self.e = []  # List to store edges
        self.id = [0] * (n + 1)  # Array to store the index of each vertex in the sorted edge list

    def add_edge(self, x, y, c):
        self.e.append(Edge(x, y, c))
        self.e.append(Edge(y, x, c))

def read_graph():
    n = int(input())  # Read the number of vertices
    g = Graph(n)  # Initialize the graph
    for _ in range(n - 1):
        x, y, c = map(int, input().split())
        g.add_edge(x, y, c)  # Add edges to the graph
    g.e.sort(key=lambda edge: (edge.s, edge.g))  # Sort edges based on source and destination
    p = 0
    for i in range(g.vcnt):
        while p < len(g.e) and g.e[p].s < i:
            p += 1
        g.id[i] = p
    g.id[g.vcnt] = len(g.e)  # Set the last index as a sentinel
    return g

def dfs(g, s, tyokkeitemp):
    for i in range(g.id[s], g.id[s + 1]):
        if tyokkeitemp[g.e[i].g] == 0:  # If the destination vertex has not been visited yet
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c  # Update the depth
            dfs(g, g.e[i].g, tyokkeitemp)  # Recursive DFS call

def find_diameter(g):
    tyokkeitemp = [0] * (g.vcnt + 10)  # Array to store the depth of each vertex from the root
    tyokkeitemp[0] = 1  # Initialize the root vertex depth to 1
    dfs(g, 0, tyokkeitemp)  # Perform DFS from the root vertex
    M = 0
    Mi = 0
    for i in range(g.vcnt):
        if tyokkeitemp[i] > M:  # Find the maximum depth
            M = tyokkeitemp[i]
            Mi = i
    return M - 1  # Return the diameter which is the maximum depth minus 1

# Main function to read the graph and print the diameter
if __name__ == "__main__":
    g = read_graph()  # Read the graph
    print(find_diameter(g))  # Call the find_diameter function to find the diameter

# <END-OF-CODE>
