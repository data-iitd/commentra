import sys

def maxMatching(v, p):
    a = 0 # Number of matched pairs
    o = 0 # Number of unmatched nodes
    for w in g[v]:
        if w == p: continue # Skip the parent node
        r = maxMatching(w, v) # Recursively calculate matching for child nodes
        a += r // 2 # Add half of the matches from the child
        o += r % 2 # Count the unmatched nodes
    return 2 * a + min(1, o) + 1 # Return the total number of matches

if __name__ == "__main__":
    n = int(sys.stdin.readline()) # Read the number of nodes
    g = [[] for _ in range(n)] # Initialize the graph's adjacency list
    for i in range(n - 1): # Read the edges and construct the graph
        a, b = map(int, sys.stdin.readline().split()) # Read node a and b and convert to 0-based index
        g[a].append(b) # Add edge from a to b
        g[b].append(a) # Add edge from b to a
    m = maxMatching(0, -1) // 2 # Calculate the maximum matching
    print("Second" if 2 * m == n else "First") # Determine the winner and print the result

