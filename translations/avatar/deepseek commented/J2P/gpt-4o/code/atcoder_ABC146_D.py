class Edge:  # Define the Edge class
    def __init__(self, id, to):
        self.id = id
        self.to = to

def dfs(to, color, parent):  # Step 4: Define the DFS function
    global k
    k = 1  # Initialize the color counter
    for e in g[to]:  # Iterate through the adjacency list of the current node
        if e.to == parent:
            continue  # Skip if the neighbor is the parent
        if k == color:
            k += 1  # Ensure the color is not the same as the parent's color
        ans[e.id] = k  # Assign the color to the edge
        dfs(e.to, k, to)  # Recursively call DFS for the neighbor
        k += 1  # Increment the color counter for the next edge

n = int(input())  # Read the number of nodes
g = [[] for _ in range(n)]  # Initialize the graph as an adjacency list
for i in range(n - 1):  # Step 2: Read and populate the graph
    a, b = map(int, input().split())  # Read nodes a and b
    a -= 1  # Convert to 0-based index
    b -= 1  # Convert to 0-based index
    g[a].append(Edge(i, b))  # Add edge from a to b
    g[b].append(Edge(i, a))  # Add edge from b to a

ans = [0] * (n - 1)  # Step 3: Initialize the answer array
dfs(0, -1, -1)  # Step 3: Call DFS with root node 0, initial color -1, and parent -1

max_color = max(ans)  # Step 5: Find the maximum color used
print(max_color)  # Step 5: Print the maximum color used
for c in ans:
    print(c)  # Step 5: Print the colors assigned to each edge

# <END-OF-CODE>
