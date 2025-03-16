from collections import defaultdict  # Import defaultdict for easier graph representation
import sys  # Import sys to manipulate recursion limit
sys.setrecursionlimit(10 ** 7)  # Set recursion limit to a high value to handle deep recursions

# Initialize a graph using defaultdict to store adjacency lists
graph = defaultdict(list)

# Read the number of nodes (N) and the number of colors (K) from input
N, K = map(int, input().split())

# Build the graph by reading N-1 edges
for i in range(N - 1):
    a, b = map(int, input().split())  # Read each edge
    graph[a - 1].append(b - 1)  # Add edge from a to b (0-indexed)
    graph[b - 1].append(a - 1)  # Add edge from b to a (0-indexed)

mod = 10 ** 9 + 7  # Define a modulus for the result to prevent overflow

# Define a recursive function to perform depth-first search (DFS) and count valid colorings
def dfs(fro, to, f):
    caseNum = f  # Initialize case number with the current color
    colorNum = K - 1 if f == K else K - 2  # Determine the number of available colors for the next node
    
    # Iterate through all adjacent nodes in the graph
    for u in graph[fro]:
        if u == to:  # Skip the node we came from to avoid cycles
            continue
        pat = dfs(u, fro, colorNum)  # Recursively call DFS for the adjacent node
        if pat == 0:  # If no valid coloring is found, break out
            caseNum = 0
            break
        caseNum = caseNum * pat % mod  # Update the case number with the valid patterns found
        colorNum -= 1  # Decrease the available colors for the next node
    
    return caseNum  # Return the total valid colorings found

# Start the DFS from the root node (0) with no parent (-1) and K colors
ans = dfs(0, -1, K)

# Print the final answer which is the number of valid colorings
print(ans)
