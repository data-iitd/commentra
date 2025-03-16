
# This is a Python code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.
#
# #include <stdio.h>
# #include <stdlib.h>
# #define ll long long
# #define rep(i,l,r)for(ll i=(l);i<(r);i++)
# #define max(p,q)((p)>(q)?(p):(q))

# Define the structure for the edge and graph.
class E:
	def __init__(self,s,g,c):
		self.s = s
		self.g = g
		self.c = c
class G:
	def __init__(self):
		self.vcnt = 0
		self.ecnt = 0
		self.e = []
		self.id = []

# Comparison function for qsort to sort edges based on their source vertex.
def esort(a,b):
	p = a
	q = b
	if(p.s<q.s):return -1
	if(p.s>q.s):return  1
	if(p.g<q.g):return -1
	return 1

# Initialize the graph structure.
g = G()

# Read the graph from the standard input.
def readgraph():
	# Read the number of vertices.
	n = int(input())
	# Allocate memory for the vertices and edges.
	g.vcnt = n
	g.ecnt = 2*n-2
	# Allocate memory for the edge array and sort it.
	g.e = [E(0,0,0) for i in range(g.ecnt+10)]
	for i in range(n-1):
		x,y,c = map(int,input().split())
		# Add an edge from x to y and y to x with the given cost.
		g.e[i].s = x
		g.e[i].g = y
		g.e[i].c = c
		g.e[i+g.ecnt].s = y
		g.e[i+g.ecnt].g = x
		g.e[i+g.ecnt].c = c
	# Set the number of edges.
	g.ecnt *= 2
	# Sort the edges using qsort.
	g.e.sort(key=cmp_to_key(esort))
	# Initialize the id array.
	p = 0
	for i in range(g.vcnt):
		# Find the index of the current vertex in the sorted edge list.
		while(p<g.ecnt and g.e[p].s<i):p+=1
		g.id.append(p)
	# Set the last index as a sentinel.
	g.id.append(g.ecnt)

# Function to find the diameter of the tree using DFS algorithm.
# *tyokkeitemp is an array to store the depth of each vertex from the root.
tyokkeitemp = []
def tyokkeidfs(s):
	# Iterate through the edges connected to the current vertex.
	for i in range(g.id[s],g.id[s+1]):
		# If the destination vertex has not been visited yet, recursively call tyokkeidfs.
		if(tyokkeitemp[g.e[i].g]==0):
			tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c
			tyokkeidfs(g.e[i].g)

def tyokkei():
	# Allocate memory for tyokkeitemp array.
	tyokkeitemp = [0 for i in range(g.vcnt+10)]
	# Initialize the root vertex depth to 1.
	tyokkeitemp[0] = 1
	# Perform DFS from the root vertex.
	tyokkeidfs(0)
	# Find the maximum depth.
	M = 0
	Mi = 0
	for i in range(g.vcnt):
		# If the current vertex depth is greater than the maximum depth, update it.
		if(tyokkeitemp[i]>M):
			M = tyokkeitemp[i]
			Mi = i
	# Return the diameter which is the maximum depth minus 1.
	return M-1

# Main function to read the graph and print the diameter.
readgraph()
print(tyokkei())
# 