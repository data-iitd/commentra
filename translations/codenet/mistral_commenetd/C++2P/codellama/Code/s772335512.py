
#include <iostream> // Include the iostream library for input and output operations
#include <vector> // Include the vector library for creating dynamic arrays

using namespace std; // Use the standard namespace for easier access to library functions

G = [[] for _ in range(100000)] # Declare an adjacency list named G with a maximum size of 100000
used = [False for _ in range(100000)] # Declare a boolean array named used to keep track of visited vertices
grundy = [0 for _ in range(100000)] # Declare an array named grundy to store the Grundy numbers of vertices

def dfs(v): # Define a recursive depth-first search function named dfs
    used[v] = True # Set the visited status of the current vertex to true
    grundy[v] = 0 # Initialize the Grundy number of the current vertex to 0
    for i in range(len(G[v])): # Iterate through all the neighbors of the current vertex
        w = G[v][i] # Assign the neighbor to a temporary variable w
        if not used[w]: # If the neighbor has not been visited yet
            dfs(w) # Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w]+1) # Update the Grundy number of the current vertex based on the neighbor's Grundy number

N = int(input()) # Declare an integer variable named N to store the number of vertices
for i in range(N-1): # Iterate through all the edges except the last one
    x, y = map(int, input().split()) # Read the endpoints of an edge from the standard input
    x -= 1; y -= 1 # Decrease the indices of x and y by 1 to make them zero-indexed
    G[x].append(y) # Add an edge from x to y to the adjacency list
    G[y].append(x) # Add a reciprocal edge from y to x to the adjacency list

dfs(0) # Call the dfs function starting from vertex 0
if grundy[0] != 0: # Check if the Grundy number of the root vertex is non-zero
    print("Alice") # If so, print "Alice" to the standard output
else: # Otherwise
    print("Bob") # Print "Bob" to the standard output

