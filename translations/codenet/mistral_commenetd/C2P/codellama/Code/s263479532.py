
#include<stdio.h>
#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

def prim(): # Function to implement Prim's Algorithm
    d = [INF] * n # Declare and initialize variables
    pi = [NIL] * n
    color = [WHITE] * n
    d[0] = 0 # Set the initial distance of the first vertex to 0
    while True: # The main loop of Prim's Algorithm
        mincost = INF # Initialize mincost to the maximum possible value
        for i in range(n): # Find the unvisited vertex with the minimum distance
            if color[i] != BLACK and d[i] < mincost:
                mincost = d[i]
                u = i
        if mincost == INF: break # If all vertices have been visited, break the loop
        color[u] = BLACK # Mark the current vertex as visited
        for v in range(n): # Update the distances of adjacent vertices
            if color[v] != BLACK and G[u][v] < d[v] and G[u][v] != -1:
                pi[v] = u
                d[v] = G[u][v]
    sum = 0 # Calculate and print the total weight of the MST
    for i in range(n):
        if d[i] != INF: sum += d[i]
    return sum

n = int(input()) # Read the number of vertices from the user
G = [[0] * n for i in range(n)] # Initialize the 2D array G with input values
for i in range(n):
    for j in range(n):
        G[i][j] = int(input())

print(prim()) # Call the prim function and print the result

