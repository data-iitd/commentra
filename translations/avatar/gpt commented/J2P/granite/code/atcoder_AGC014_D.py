
import sys
from collections import defaultdict

def max_matching(v, p):
    a = 0 # Count of pairs in matching
    o = 0 # Count of unmatched vertices
    
    # Iterate through all adjacent vertices of v
    for w in g[v]:
        # Skip the parent vertex to avoid cycles
        if w == p: continue 
        
        # Recursively find the matching for the adjacent vertex
        r = max_matching(w, v) 
        a += r // 2 # Update count of pairs
        o += r % 2 # Update count of unmatched vertices
    
    # Return the total matching count
    return 2 * a + min(1, o) + 1

def main():
    # Initialize input reader
    data = iter(sys.stdin.read().split("\n"))
    # Read the number of vertices
    n = int(next(data))
    # Initialize the adjacency list for the graph
    g = defaultdict(list)
    # Read edges and populate the adjacency list
    for _ in range(n - 1):
        a, b = map(int, next(data).split())
        g[a].append(b)
        g[b].append(a) # Add edge to the graph (undirected)
    
    # Calculate maximum matching starting from vertex 0
    m = max_matching(0, -1) // 2
    
    # Determine the winner based on the matching result
    print("Second" if 2 * m == n else "First")

if __name__ == "__main__":
    main()

