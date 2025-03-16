
import sys

# Define the maximum number of vertices
MAX = 101

# Define color constants
WHITE = 0
BLACK = 2
GRAY = 1

# Global variables: time counter, number of vertices, and adjacency matrix
time = 0
n = 0
g = [[0 for _ in range(MAX)] for _ in range(MAX)]

# Arrays for discovery time, finish time, and color of nodes
d = [0] * MAX
f = [0] * MAX
color = [WHITE] * MAX

# Function to perform DFS visit on a node
def visit(u):
    global time
    color[u] = GRAY
    d[u] = time + 1
    time += 1
    for i in range(n):
        if g[u][i] == 0:
            continue
        if color[i] == WHITE:
            visit(i)
    color[u] = BLACK
    f[u] = time + 1
    time += 1

# Function to perform Depth-First Search on the graph
def dfs():
    global time
    time = 0
    for i in range(n):
        if color[i] == WHITE:
            visit(i)
    for i in range(n):
        print(f"{i + 1} {d[i]} {f[i]}")

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

