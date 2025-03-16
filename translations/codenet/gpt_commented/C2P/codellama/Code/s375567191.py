#include <stdio.h>
#define MAX 101          # Define the maximum number of vertices
#define WHITE 0          # Color constant for unvisited nodes
#define BLACK 2          # Color constant for fully explored nodes
#define GRAY 1           # Color constant for nodes currently being explored

n = 0                    # Global variables: number of vertices, and adjacency matrix
g = [[0] * MAX] * MAX     # Arrays for discovery time, finish time, and color of nodes
d = [0] * MAX
f = [0] * MAX
color = [WHITE] * MAX
time = 0                 # Initialize time counter

# Function to perform DFS visit on a node
def visit(u):
    global time
    global n
    global g
    global d
    global f
    global color

    color[u] = GRAY        # Mark the node as being explored
    d[u] = time            # Set the discovery time for the node
    time += 1              # Increment the time counter

    # Explore all adjacent nodes
    for i in range(n):
        if g[u][i] == 0:   # If there is no edge to node i, skip
            continue
        if color[i] == WHITE: # If the adjacent node is unvisited
            visit(i)          # Recursively visit the adjacent node

    color[u] = BLACK        # Mark the node as fully explored
    f[u] = time             # Set the finish time for the node
    time += 1               # Increment the time counter

# Function to perform Depth-First Search on the graph
def dfs():
    global time
    global n
    global g
    global d
    global f
    global color

    # Visit all nodes in the graph
    for i in range(n):
        if color[i] == WHITE: # If the node is unvisited
            visit(i)          # Start a DFS visit

    # Print the discovery and finish times for each node
    for i in range(n):
        print(i + 1, d[i], f[i]) # Output: node index, discovery time, finish time

# Main function
def main():
    global n
    global g
    global d
    global f
    global color
    global time

    # Read the number of vertices
    n = int(input())

    # Read the graph edges
    for i in range(n):
        x = int(input())
        y = int(input())
        for j in range(y):
            z = int(input())
            g[x - 1][z - 1] = 1

    # Perform DFS on the graph
    dfs()

# Main function call
main()

# 