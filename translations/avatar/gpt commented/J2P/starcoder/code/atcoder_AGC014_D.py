import sys
import io

# Adjacency list to represent the graph
g = []

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
        a += r / 2 # Update count of pairs
        o += r % 2 # Update count of unmatched vertices
    
    # Return the total matching count
    return 2 * a + min(1, o) + 1

# Main function
def main():
    # Read the number of vertices
    n = int(input())
    # Initialize the adjacency list for the graph
    g = [[] for i in range(n)]
    
    # Read edges and populate the adjacency list
    for i in range(n - 1):
        a = int(input()) - 1 # Read vertex a
        b = int(input()) - 1 # Read vertex b
        g[a].append(b) # Add edge to the graph
        g[b].append(a) # Add edge to the graph (undirected)
    
    # Calculate maximum matching starting from vertex 0
    m = maxMatching(0, -1) / 2
    
    # Determine the winner based on the matching result
    print("Second" if 2 * m == n else "First")

# Entry point of program
if __name__ == "__main__":
    main()

