N = 200          # Maximum number of nodes
SHIRO = 0       # Color constant for unvisited nodes
HAI = 1         # Color constant for visiting nodes
KURO = 2        # Color constant for visited nodes

# Function prototypes
def aaaaa():         # Function to perform depth-first search (DFS) and print discovery and finishing times
    global TT
    for i in range(n):
        color[i] = SHIRO
    
    TT = 0  # Reset the time counter

    # Perform DFS for each unvisited node
    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u)  # Call DFS for the unvisited node

    # Print the discovery and finishing times for each node
    for i in range(n):
        print(i + 1, d[i], f[i])  # Output format: node index, discovery time, finishing time

def bbbbb(k):  # Recursive function to visit nodes in DFS
    global TT
    color[k] = HAI  # Mark the current node as visiting (HAI)
    TT += 1  # Increment the time counter
    d[k] = TT  # Set the discovery time for the current node

    # Visit all adjacent nodes
    for v in range(n):
        if A[k][v] == 0:
            continue  # Skip if there is no edge
        if color[v] == SHIRO:  # If the adjacent node is unvisited
            bbbbb(v)  # Recursively visit the adjacent node

    color[k] = KURO  # Mark the current node as visited (KURO)
    f[k] = TT + 1  # Set the finishing time for the current node
    TT += 1

# Main program
n = int(input())  # Read the number of nodes
A = [[0] * N for _ in range(N)]  # Initialize the adjacency matrix to zero (no edges)

# Read the edges for each node
for i in range(n):
    u, k = map(int, input().split())  # Read node u and number of edges k
    u -= 1  # Convert to zero-based index
    for _ in range(k):
        v = int(input())  # Read each adjacent node v
        v -= 1  # Convert to zero-based index
        A[u][v] = 1  # Mark the edge in the adjacency matrix

color = [0] * N  # Array to store colors
d = [0] * N     # Array to store discovery times
f = [0] * N     # Array to store finishing times
TT = 0          # Global variable to keep track of time during DFS

# Call the DFS function to process the graph
aaaaa()

# End of the code
# <END-OF-CODE>
