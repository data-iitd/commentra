
# depth first search algorithm implementation in Python

import sys

N = 100 # maximum number of vertices in the graph
WHITE = 0 # unvisited vertex
GRAY = 1 # vertex is being explored
BLACK = 2 # vertex has been explored

M = [[0 for i in range(N)] for j in range(N)] # adjacency matrix and number of vertices
color = [WHITE for i in range(N)] # arrays for depth first search
d = [0 for i in range(N)] # record the discovery time
f = [0 for i in range(N)] # record the finishing time
tt = 0 # time counter

# depth first search visit function
# sets the color, depth and finishing time of a vertex
def dfs_visit(u):
    global tt
    color[u] = GRAY # mark the current vertex as being explored
    d[u] = tt + 1 # record the discovery time
    for v in range(N):
        if M[u][v] == 0:
            continue # if there is no edge between u and v, skip
        if color[v] == WHITE:
            dfs_visit(v) # recursively call dfs_visit for the neighbor v
    color[u] = BLACK # mark the current vertex as explored
    f[u] = tt + 1 # record the finishing time
    global tt
    tt += 1

# depth first search function
# initializes the arrays and performs the DFS traversal
def dfs():
    for i in range(N):
        color[i] = WHITE # initialize all vertices as unvisited
    global tt
    tt = 0

    for u in range(N):
        if color[u] == WHITE:
            dfs_visit(u) # call dfs_visit for the first unvisited vertex

    # print the results
    for i in range(N):
        print(str(i + 1) + " " + str(d[i]) + " " + str(f[i]))

if __name__ == "__main__":
    n = int(input()) # read the number of vertices

    # initialize the adjacency matrix with zeros
    for i in range(n):
        for j in range(n):
            M[i][j] = 0

    # read the edges and fill the adjacency matrix
    for i in range(n):
        u, k = map(int, input().split())
        u -= 1
        for j in range(k):
            v = int(input())
            v -= 1
            M[u][v] = 1

    # perform depth first search
    dfs()

