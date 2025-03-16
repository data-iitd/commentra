MAX = 101
WHITE = 0
BLACK = 2
GRAY = 1

time = 0
n = 0
g = [[0] * MAX for _ in range(MAX)]  # initialize 2D adjacency matrix g
d = [0] * MAX  # depth array
f = [0] * MAX  # finish array
color = [WHITE] * MAX  # color array

def visit(u):  # function to perform Depth First Search (DFS) from vertex 'u'
    global time
    color[u] = GRAY  # mark the current vertex as 'gray'
    time += 1
    d[u] = time  # assign depth value to the current vertex

    for i in range(n):  # iterate through all the adjacent vertices of 'u'
        if g[u][i] == 0:  # if there is no edge between 'u' and 'i'
            continue
        if color[i] == WHITE:  # if 'i' is not yet visited
            visit(i)  # recursively call DFS on 'i'

    color[u] = BLACK  # mark the current vertex as 'black'
    time += 1
    f[u] = time  # assign finish value to the current vertex

def dfs():  # function to perform DFS on the entire graph
    global time
    time = 0  # initialize time counter

    for i in range(n):  # iterate through all the vertices in the graph
        if color[i] == WHITE:  # if 'i' is not yet visited
            visit(i)  # recursively call DFS on 'i'

    for i in range(n):  # print the depth, finish, and vertex number for each vertex
        print(i + 1, d[i], f[i])

if __name__ == "__main__":  # main function
    n = int(input())  # read the number of vertices in the graph

    for i in range(n):  # iterate through each vertex in the graph
        x, y = map(int, input().split())  # read the number of edges and their destinations for the current vertex

        for j in range(y):  # iterate through all the edges for the current vertex
            z = int(input())  # read the destination vertex for the current edge
            g[x - 1][z - 1] = 1  # mark that there is an edge between 'x' and 'z'

    dfs()  # call DFS function to perform DFS on the entire graph

# <END-OF-CODE>
