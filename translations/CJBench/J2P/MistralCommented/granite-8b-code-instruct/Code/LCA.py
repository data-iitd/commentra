

import sys

def dfs(adj, s, p, parent, depth):
    for adjacent in adj[s]: # Iterate through each neighbor of the current vertex
        if adjacent!= p: # Check if the neighbor is not the parent of the current vertex
            parent[adjacent] = s # Set the parent of the neighbor to the current vertex
            depth[adjacent] = 1 + depth[s] # Update the depth of the neighbor by adding 1 to the depth of the current vertex
            dfs(adj, adjacent, s, parent, depth) # Recursively call the DFS algorithm for the neighbor

def getMain(v1, v2, depth, parent):
    if depth[v1] < depth[v2]: # Check if the depth of v1 is smaller than the depth of v2
        temp = v1
        v1 = v2
        v2 = temp # Swap the values of v1 and v2 if the depth of v1 is smaller
    while depth[v1]!= depth[v2]: # Traverse up the tree from v1 to find the Main
        v1 = parent[v1]
    if v1 == v2: # Check if v1 and v2 are the same vertex
        return v1 # Return the vertex if they are the same
    while v1!= v2: # Traverse up the tree from v1 to find the Main
        v1 = parent[v1]
        v2 = parent[v2]
    return v1 # Return the Main of v1 and v2

def main():
    v = int(input()) # Read the number of vertices (nodes) from the input

    adj = [[] for _ in range(v)] # Initialize a list of lists to store the adjacency list

    for _ in range(v - 1): # Iterate through each edge and add it to the adjacency list
        u, v = map(int, input().split())
        adj[u].append(v) # Add the neighbor to the list of neighbors of the current vertex
        adj[v].append(u) # Add the current vertex to the list of neighbors of the neighbor

    parent = [0] * v # Initialize an integer array to store the parent of each vertex
    depth = [0] * v # Initialize an integer array to store the depth of each vertex

    dfs(adj, 0, -1, parent, depth) # Call the depth-first search algorithm starting from vertex 0

    v1, v2 = map(int, input().split()) # Read the first vertex and the second vertex from the input

    print(getMain(v1, v2, depth, parent)) # Call the function to find the Main (Lowest Common Ancestor) of the two vertices and print the result

if __name__ == "__main__":
    main() # Call the main function

