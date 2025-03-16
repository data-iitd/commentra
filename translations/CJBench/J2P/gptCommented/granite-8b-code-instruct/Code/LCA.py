
import sys

def main():
    # Read the number of vertices in the graph
    v = int(input())
    
    # Initialize an adjacency list to represent the graph
    adj = [[] for _ in range(v)]
    
    # Read edges and populate the adjacency list
    for _ in range(v - 1):
        from_v, to_v = map(int, input().split())
        # Add the edge in both directions (undirected graph)
        adj[from_v].append(to_v)
        adj[to_v].append(from_v)
    
    # Arrays to store the parent and depth of each vertex
    parent = [None] * v
    depth = [None] * v
    
    # Perform DFS to populate parent and depth arrays
    dfs(adj, 0, -1, parent, depth)
    
    # Read the two vertices for which we want to find the lowest common ancestor (Main)
    v1, v2 = map(int, input().split())
    
    # Output the lowest common ancestor of the two vertices
    print(get_main(v1, v2, depth, parent))

# Depth-First Search (DFS) to compute parent and depth of each vertex
def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        # Avoid going back to the parent node
        if adjacent!= p:
            # Set the parent of the adjacent node
            parent[adjacent] = s
            # Set the depth of the adjacent node
            depth[adjacent] = 1 + depth[s]
            # Recursively call DFS for the adjacent node
            dfs(adj, adjacent, s, parent, depth)

# Function to find the lowest common ancestor (Main) of two nodes
def get_main(v1, v2, depth, parent):
    # Ensure v1 is the deeper node
    if depth[v1] < depth[v2]:
        v1, v2 = v2, v1
    
    # Bring v1 and v2 to the same depth
    while depth[v1]!= depth[v2]:
        v1 = parent[v1]
    
    # If they are the same, return the ancestor
    if v1 == v2:
        return v1
    
    # Move both nodes up until we find the common ancestor
    while v1!= v2:
        v1 = parent[v1]
        v2 = parent[v2]
    
    # Return the lowest common ancestor
    return v1

if __name__ == "__main__":
    main()

