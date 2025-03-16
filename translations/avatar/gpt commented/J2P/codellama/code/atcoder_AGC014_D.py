import sys 

# Adjacency list to represent the graph
g = [[] for _ in range(int(sys.stdin.readline().strip()))] 

# Function to calculate the maximum matching in the graph
def maxMatching(v, p): 
    a = 0 # Count of pairs in matching
    o = 0 # Count of unmatched vertices
    
    # Iterate through all adjacent vertices of v
    for w in g[v]:
        # Skip the parent vertex to avoid cycles
        if w == p: continue
        
        # Recursively find the matching for the adjacent vertex
        r = maxMatching(w, v)
        a += r // 2 # Update count of pairs
        o += r % 2 # Update count of unmatched vertices
    
    # Return the total matching count
    return 2 * a + min(1, o) + 1

# Read the number of vertices
n = int(sys.stdin.readline().strip())

# Read edges and populate the adjacency list
for i in range(n - 1):
    a, b = map(int, sys.stdin.readline().strip().split())
    g[a - 1].append(b - 1) # Add edge to the graph
    g[b - 1].append(a - 1) # Add edge to the graph (undirected)

# Calculate maximum matching starting from vertex 0
m = maxMatching(0, -1) // 2

# Determine the winner based on the matching result
print("Second" if 2 * m == n else "First")

# End of code
