

import sys # Import the sys module for input and output operations
from collections import defaultdict # Import the defaultdict class from the collections module for creating dictionaries with default values

N = int(input()) # Read the number of vertices from the standard input
G = defaultdict(list) # Create a dictionary named G with default value [] to store the adjacency list
for i in range(N-1): # Iterate through all the edges except the last one
    x, y = map(int, input().split()) # Read the endpoints of an edge from the standard input and convert them to integers
    G[x].append(y) # Add an edge from x to y to the adjacency list
    G[y].append(x) # Add a reciprocal edge from y to x to the adjacency list

used = [False]*(N+1) # Create a boolean array named used with a length of N+1 to keep track of visited vertices
grundy = [0]*(N+1) # Create an array named grundy with a length of N+1 to store the Grundy numbers of vertices

def dfs(v): # Define a recursive depth-first search function named dfs
    used[v] = True # Set the visited status of the current vertex to true
    grundy[v] = 0 # Initialize the Grundy number of the current vertex to 0
    for w in G[v]: # Iterate through all the neighbors of the current vertex
        if not used[w]: # If the neighbor has not been visited yet
            dfs(w) # Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w]+1) # Update the Grundy number of the current vertex based on the neighbor's Grundy number

dfs(1) # Call the dfs function starting from vertex 1
if grundy[1]!= 0: # Check if the Grundy number of the root vertex is non-zero
    print("Alice") # If so, print "Alice" to the standard output
else: # Otherwise
    print("Bob") # Print "Bob" to the standard output

