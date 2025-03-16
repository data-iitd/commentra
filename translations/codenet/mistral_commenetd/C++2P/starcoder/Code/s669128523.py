
# depth first search algorithm implementation in Python
# not lying in the stack

N = 100 # maximum number of vertices in the graph
WHITE = 0 # unvisited vertex
GRAY = 1 # vertex is being explored
BLACK = 2 # vertex has been explored

M = [[0 for i in range(N)] for j in range(N)] # adjacency matrix
n = 0 # number of vertices
color = [0 for i in range(N)] # array for depth first search
d = [0 for i in range(N)] # array for depth first search
f = [0 for i in range(N)] # array for depth first search
tt = 0 # time stamp

# depth first search visit function
# sets the color, depth and finishing time of a vertex
def dfs_visit(u):
	global tt
	v = 0
	color[u] = GRAY # mark the current vertex as being explored
	d[u] = tt = tt + 1 # record the discovery time
	for v in range(n):
		if M[u][v] == 0:
			continue # if there is no edge between u and v, skip
		if color[v] == WHITE:
			dfs_visit(v) # recursively call dfs_visit for the neighbor v
	color[u] = BLACK # mark the current vertex as explored
	f[u] = tt = tt + 1 # record the finishing time

# depth first search function
# initializes the arrays and performs the DFS traversal
def dfs():
	global n
	u = 0
	for i in range(n):
		color[i] = WHITE # initialize all vertices as unvisited
	tt = 0

	for u in range(n):
		if color[u] == WHITE:
			dfs_visit(u) # call dfs_visit for the first unvisited vertex

	# print the results
	for i in range(n):
		print(i + 1, d[i], f[i])

# read the number of vertices
n = int(input())

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

# 