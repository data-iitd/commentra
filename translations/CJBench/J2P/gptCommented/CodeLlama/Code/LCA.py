import sys

def main():
    # Read the number of vertices in the graph
    v = int(sys.stdin.readline())
    
    # Initialize an adjacency list to represent the graph
    adj = [[] for _ in range(v)]
    
    # Read edges and populate the adjacency list
    for i in range(v - 1):
        from_vertex, to_vertex = map(int, sys.stdin.readline().split())
        # Add the edge in both directions (undirected graph)
        adj[from_vertex].append(to_vertex)
        adj[to_vertex].append(from_vertex)
    
    # Arrays to store the parent and depth of each vertex
    parent = [-1] * v
    depth = [0] * v
    
    # Perform DFS to populate parent and depth arrays
    dfs(adj, 0, -1, parent, depth)
    
    # Read the two vertices for which we want to find the lowest common ancestor (Main)
    v1, v2 = map(int, sys.stdin.readline().split())
    
    # Output the lowest common ancestor of the two vertices
    print(get_main(v1, v2, depth, parent))

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]:
        # Avoid going back to the parent node
        if adjacent != p:
            # Set the parent of the adjacent node
            parent[adjacent] = s
            # Set the depth of the adjacent node
            depth[adjacent] = 1 + depth[s]
            # Recursively call DFS for the adjacent node
            dfs(adj, adjacent, s, parent, depth)

def get_main(v1, v2, depth, parent):
    # Ensure v1 is the deeper node
    if depth[v1] < depth[v2]:
        v1, v2 = v2, v1
    
    # Bring v1 and v2 to the same depth
    while depth[v1] != depth[v2]:
        v1 = parent[v1]
    
    # If they are the same, return the ancestor
    if v1 == v2:
        return v1
    
    # Move both nodes up until we find the common ancestor
    while v1 != v2:
        v1 = parent[v1]
        v2 = parent[v2]
    
    # Return the lowest common ancestor
    return v1

if __name__ == "__main__":
    main()

