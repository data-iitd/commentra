# Import the necessary libraries
from collections import defaultdict

# Create an adjacency list using defaultdict
G = defaultdict(list)  # Adjacency list for the graph
used = []  # List to keep track of visited vertices
grundy = []  # List to store the Grundy numbers of vertices

def dfs(v):  # Define a recursive depth-first search function named dfs
    used[v] = True  # Set the visited status of the current vertex to true
    grundy[v] = 0  # Initialize the Grundy number of the current vertex to 0
    for w in G[v]:  # Iterate through all the neighbors of the current vertex
        if not used[w]:  # If the neighbor has not been visited yet
            dfs(w)  # Recursively call the dfs function for the neighbor
            grundy[v] ^= (grundy[w] + 1)  # Update the Grundy number of the current vertex

def main():  # Define the main function
    N = int(input())  # Read the number of vertices from the standard input
    global used, grundy  # Declare used and grundy as global variables
    used = [False] * N  # Initialize the used list with False
    grundy = [0] * N  # Initialize the grundy list with 0

    for _ in range(N - 1):  # Iterate through all the edges except the last one
        x, y = map(int, input().split())  # Read the endpoints of an edge from the standard input
        x -= 1  # Decrease the index of x by 1 to make it zero-indexed
        y -= 1  # Decrease the index of y by 1 to make it zero-indexed
        G[x].append(y)  # Add an edge from x to y to the adjacency list
        G[y].append(x)  # Add a reciprocal edge from y to x to the adjacency list

    dfs(0)  # Call the dfs function starting from vertex 0
    if grundy[0] != 0:  # Check if the Grundy number of the root vertex is non-zero
        print("Alice")  # If so, print "Alice" to the standard output
    else:  # Otherwise
        print("Bob")  # Print "Bob" to the standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
