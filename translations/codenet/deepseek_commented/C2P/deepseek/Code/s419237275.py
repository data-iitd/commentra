N = 200  # Maximum number of nodes in the graph
SHIRO = 0  # Color representing unvisited nodes
HAI = 1  # Color representing nodes currently in the recursion stack
KURO = 2  # Color representing nodes fully processed

# Function prototypes
def aaaaa():
    pass

def bbbbb(k):
    pass

# Initialize global variables
n = 0
A = [[0] * N for _ in range(N)]  # Adjacency matrix
color = [SHIRO] * N  # Color of each node
d = [0] * N  # Discovery time
f = [0] * N  # Finish time
TT = 0  # Time counter

# Read the number of nodes
n = int(input())

# Read the edges for each node and update the adjacency matrix
for i in range(n):
    u, k = map(int, input().split())
    u -= 1  # Adjust for 0-based indexing
    for _ in range(k):
        v = int(input())
        v -= 1  # Adjust for 0-based indexing
        A[u][v] = 1

# Perform DFS and print the results
aaaaa()

# Print the discovery and finish times for each node
for i in range(n):
    print(f"{i + 1} {d[i]} {f[i]}")

# End-of-code
