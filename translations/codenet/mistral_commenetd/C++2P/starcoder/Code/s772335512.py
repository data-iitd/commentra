
# Include the iostream library for input and output operations
# Include the vector library for creating dynamic arrays

from sys import stdin, stdout # Import the standard input and output functions

# Declare an adjacency list named G with a maximum size of 100000
G = [[] for i in range(100000)]

# Declare a boolean array named used to keep track of visited vertices
used = [False for i in range(100000)]

# Declare an array named grundy to store the Grundy numbers of vertices
grundy = [0 for i in range(100000)]

def dfs(v): # Define a recursive depth-first search function named dfs
    used[v] = True # Set the visited status of the current vertex to true
    grundy[v] = 0 # Initialize the Grundy number of the current vertex to 0
    for w in G[v]: # Iterate through all the neighbors of the current vertex
        if not used[w]: # If the neighbor has not been visited yet
            dfs(w) # Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w]+1) # Update the Grundy number of the current vertex based on the neighbor's Grundy number

def main(): # Define the main function
    N = int(stdin.readline()) # Read the number of vertices from the standard input
    for i in range(N-1): # Iterate through all the edges except the last one
        x, y = map(int, stdin.readline().split()) # Read the endpoints of an edge from the standard input
        x -= 1; y -= 1 # Decrease the indices of x and y by 1 to make them zero-indexed
        G[x].append(y) # Add an edge from x to y to the adjacency list
        G[y].append(x) # Add a reciprocal edge from y to x to the adjacency list
    dfs(0) # Call the dfs function starting from vertex 0
    if grundy[0]!= 0: # Check if the Grundy number of the root vertex is non-zero
        stdout.write("Alice\n") # If so, print "Alice" to the standard output
    else: # Otherwise
        stdout.write("Bob\n") # Print "Bob" to the standard output

if __name__ == "__main__": # Check if the main function has been called
    main() # If it has, call the main function

