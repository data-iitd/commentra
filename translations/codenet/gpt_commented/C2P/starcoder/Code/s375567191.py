# Define the maximum number of vertices
MAX = 101

# Define the color constants
WHITE = 0
GRAY = 1
BLACK = 2

# Global variables: time counter, number of vertices, and adjacency matrix
time = 0
n = 0
g = [[0 for i in range(MAX)] for j in range(MAX)]

# Arrays for discovery time, finish time, and color of nodes
d = [0 for i in range(MAX)]
f = [0 for i in range(MAX)]
color = [WHITE for i in range(MAX)]

# Function to perform DFS visit on a node
def visit(u):
    global time
    color[u] = GRAY
    d[u] = time
    time += 1

    for v in range(n):
        if g[u][v] == 0:
            continue
        if color[v] == WHITE:
            visit(v)

    color[u] = BLACK
    f[u] = time
    time += 1

# Function to perform Depth-First Search on the graph
def dfs():
    global time, n
    time = 0

    for u in range(n):
        if color[u] == WHITE:
            visit(u)

    for u in range(n):
        print(u + 1, d[u], f[u])

# Read the number of vertices
n = int(input())

# Read the graph edges
for i in range(n):
    x, y = map(int, input().split())
    for j in range(y):
        z = int(input())
        g[x - 1][z - 1] = 1

# Perform DFS on the graph
dfs()

# 