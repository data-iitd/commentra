# depth first search algorithm implementation in Python
N = 100  # maximum number of vertices in the graph
WHITE = 0  # unvisited vertex
GRAY = 1  # vertex is being explored
BLACK = 2  # vertex has been explored

M = [[0] * N for _ in range(N)]  # adjacency matrix
n = 0  # number of vertices
color = [WHITE] * N  # color array
d = [0] * N  # discovery time array
f = [0] * N  # finishing time array
tt = 0  # time counter

def dfs_visit(u):
    global tt
    color[u] = GRAY  # mark the current vertex as being explored
    tt += 1
    d[u] = tt  # record the discovery time
    for v in range(n):
        if M[u][v] == 0:
            continue  # if there is no edge between u and v, skip
        if color[v] == WHITE:
            dfs_visit(v)  # recursively call dfs_visit for the neighbor v
    color[u] = BLACK  # mark the current vertex as explored
    tt += 1
    f[u] = tt  # record the finishing time

def dfs():
    global tt
    for i in range(n):
        color[i] = WHITE  # initialize all vertices as unvisited
    tt = 0

    for u in range(n):
        if color[u] == WHITE:
            dfs_visit(u)  # call dfs_visit for the first unvisited vertex

    # print the results
    for i in range(n):
        print(i + 1, d[i], f[i])

if __name__ == "__main__":
    k = 0
    u = 0
    v = 0
    n = int(input())  # read the number of vertices

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

# <END-OF-CODE>
