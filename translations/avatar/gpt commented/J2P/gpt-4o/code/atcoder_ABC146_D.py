class Edge:
    def __init__(self, id, to):
        self.id = id  # Unique identifier for the edge
        self.to = to  # Destination node of the edge

def dfs(to, color, parents):
    global k
    for e in g[to]:
        if e.to == parents:
            continue
        if k == color:
            k += 1
        ans[e.id] = k
        dfs(e.to, k, to)
        k += 1

# Number of nodes in the graph
n = int(input())
# Adjacency list representation of the graph
g = [[] for _ in range(n)]
# Array to store the answer for each edge
ans = [0] * (n - 1)

# Read edges and populate the adjacency list
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1  # Adjust for 0-based indexing
    b -= 1  # Adjust for 0-based indexing
    g[a].append(Edge(i, b))
    g[b].append(Edge(i, a))

# Initialize the answer array to store results for each edge
ans = [0] * (n - 1)
k = 1  # Start coloring with color 1

# Perform a depth-first search starting from node 0
dfs(0, -1, -1)

# Find the maximum value in the ans array
max_value = max(ans)

# Output the maximum value found
print(max_value)

# Output the results for each edge
for c in ans:
    print(c)

# <END-OF-CODE>
