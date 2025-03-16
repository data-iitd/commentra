
#include <stdio.h>

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

def aaaaa():
    global n,A,color,d,f,TT

    # Initialize all nodes with color SHIRO (white)
    for i in range(n):
        color[i] = SHIRO

    TT = 0 # Initialize the time variable TT to 0

    # Perform Depth First Search (DFS) from each unvisited node
    for u in range(n):
        if color[u] == SHIRO:
            bbbbb(u)

def bbbbb(k):
    global n,A,color,d,f,TT

    color[k] = HAI # Mark the current node as visited (gray)
    TT += 1 # Increment the time variable TT
    d[k] = TT # Set the discovery time for the current node

    # Explore all neighbors of the current node
    for v in range(n):
        if A[k][v] == 1 and color[v] == SHIRO: # If the neighbor is unvisited
            bbbbb(v) # Recursively call the function bbbbb() for the neighbor

    # Mark the current node as finished (black)
    color[k] = KURO
    f[k] = TT + 1 # Set the finishing time for the current node

if __name__ == "__main__":
    n = int(input("Enter the number of nodes: ")) # Read the number of nodes from the user

    # Initialize the 2D array A with zeros
    A = [[0 for i in range(n)] for j in range(n)]

    # Read the adjacency matrix from the user
    for i in range(n):
        k = int(input("Enter the number of neighbors for node %d: " % (i+1)))
        for j in range(k):
            v = int(input("Enter the neighbor index: "))
            A[i][v-1] = 1 # Store the edge weight (assumed to be 1) in the adjacency matrix

    color = [0 for i in range(n)]
    d = [0 for i in range(n)]
    f = [0 for i in range(n)]

    aaaaa() # Call the function aaaaa() to perform the required computation

    # Print the results
    for i in range(n):
        print("%d %d %d" % (i+1,d[i],f[i]))
        print("Node %d is visited at time %d and its finishing time is %d." % (i+1,d[i],f[i]))

