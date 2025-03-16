
import sys
sys.setrecursionlimit(10**6)
def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]: # Iterate over adjacent vertices
        if adjacent!= p: # Avoid revisiting the parent vertex
            parent[adjacent] = s # Set parent of adjacent vertex
            depth[adjacent] = 1 + depth[s] # Increment depth by 1
            dfs(adj, adjacent, s, parent, depth) # Recursively call dfs for adjacent vertex
def getMain(v1, v2, depth, parent):
    if depth[v1] < depth[v2]: # Ensure v1 is at a deeper depth than v2
        temp = v1
        v1 = v2
        v2 = temp
    while depth[v1]!= depth[v2]: # Move v1 up the tree until depths are equal
        v1 = parent[v1]
    if v1 == v2: # If v1 and v2 are the same, return v1 (Main found)
        return v1
    while v1!= v2: # Move both v1 and v2 up the tree until they meet
        v1 = parent[v1]
        v2 = parent[v2]
    return v1 # Return the Main
v = int(input()) # Read the number of vertices
adj = [[] for _ in range(v)] # Initialize adjacency list for each vertex
for _ in range(v - 1):
    from_v, to_v = map(int, input().split()) # Read edge from and to
    adj[from_v].append(to_v) # Add edge to adjacency list
    adj[to_v].append(from_v) # Add edge to adjacency list (undirected graph)
parent = [0] * v # Array to store parent of each vertex
depth = [0] * v # Array to store depth of each vertex
dfs(adj, 0, -1, parent, depth) # Perform DFS starting from vertex 0
v1, v2 = map(int, input().split()) # Read first vertex and second vertex
print(getMain(v1, v2, depth, parent)) # Print the Main of v1 and v2
