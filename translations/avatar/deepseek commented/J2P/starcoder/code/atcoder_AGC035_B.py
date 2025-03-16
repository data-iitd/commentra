import sys

# Reading input
numNode = int(sys.stdin.readline())
numEdge = int(sys.stdin.readline())

# Initializing adjacency lists for each node
connect = [[] for i in range(numNode)]

# Reading edges and populating the adjacency lists
for i in range(numEdge):
    a = int(sys.stdin.readline()) - 1
    b = int(sys.stdin.readline()) - 1
    connect[a].append(b)
    connect[b].append(a)

# Checking if the number of edges is odd
if numEdge % 2!= 0:
    print(-1)
    exit()

# Initializing arrays for DFS
visited = [0 for i in range(numNode)]
odd = [False for i in range(numNode)]
print = ""

# Performing DFS starting from node 0
dfs(0, -1)

# Outputting the result
print(print)

# 