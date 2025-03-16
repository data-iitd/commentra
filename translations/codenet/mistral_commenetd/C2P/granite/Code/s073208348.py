

# This is a Python code for finding the diameter of a tree using Depth-First Search (DFS) algorithm.
#
# import sys
# sys.setrecursionlimit(10**6)
# def esort(a,b):
# 	if a[0]<b[0]:return -1
# 	if a[0]>b[0]:return  1
# 	if a[1]<b[1]:return -1
# 	return 1

# Define the structure for the edge and graph.
class E:
	def __init__(self,s,g,c):
		self.s=s
		self.g=g
		self.c=c
class G:
	def __init__(self):
		self.vcnt=0
		self.ecnt=0
		self.e=[]
		self.id=[]

# Comparison function for sorting edges based on their source vertex.
def esort(a,b):
	if a.s<b.s:return -1
	if a.s>b.s:return  1
	if a.g<b.g:return -1
	return 1

# Initialize the graph structure.
g=G()

# Read the graph from the standard input.
def readgraph():
	# Read the number of vertices.
	global g
	n=int(input())
	# Allocate memory for the vertices and edges.
	g.vcnt=n
	g.ecnt=2*n-2
	# Allocate memory for the edge array and sort it.
	g.e=[E(0,0,0) for i in range(g.ecnt+10)]
	for i in range(n-1):
		x,y,c=map(int,input().split())
		# Add an edge from x to y and y to x with the given cost.
		g.e[i].s=x
		g.e[i].g=y
		g.e[i].c=c
		g.e[i+g.ecnt].s=y
		g.e[i+g.ecnt].g=x
		g.e[i+g.ecnt].c=c
	# Sort the edges using qsort.
	g.e.sort(key=esort)
	# Set the number of edges.
	g.ecnt*=2
	# Initialize the id array.
	p=0
	for i in range(g.vcnt):
		# Find the index of the current vertex in the sorted edge list.
		while p<g.ecnt and g.e[p].s<i:p+=1
		g.id.append(p)
	# Set the last index as a sentinel.
	g.id.append(g.ecnt)

# Function to find the diameter of the tree using DFS algorithm.
def tyokkeidfs(s):
	# Iterate through the edges connected to the current vertex.
	for i in range(g.id[s],g.id[s+1]):
		# If the destination vertex has not been visited yet, recursively call tyokkeidfs.
		if g.id[g.e[i].g]==0:
			g.id[g.e[i].g]=g.id[s]+g.e[i].c
			tyokkeidfs(g.e[i].g)

def tyokkei():
	# Allocate memory for tyokkeitemp array.
	g.id=[0 for i in range(g.vcnt+10)]
	# Initialize the root vertex depth to 1.
	g.id[0]=1
	# Perform DFS from the root vertex.
	tyokkeidfs(0)
	# Find the maximum depth.
	M=0
	Mi=0
	for i in range(g.vcnt):
		# If the current vertex depth is greater than the maximum depth, update it.
		if g.id[i]>M:
			M=g.id[i]
			Mi=i
	# Return the diameter which is the maximum depth minus 1.
	return M-1

# Main function to read the graph and print the diameter.
def main():
	# Read the graph.
	readgraph()
	# Call the tyokkei function to find the diameter.
	print(tyokkei())

if __name__ == "__main__":
	main()

