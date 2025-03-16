
#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

#define E struct edge
#define G struct graph

E = {
	's': 0,
	'g': 0,
	'c': 0
}

G = {
	'vcnt': 0,
	'ecnt': 0,
	'e': [],
	'id': []
}

def esort(a,b):
	p = a
	q = b
	if p['s'] < q['s']:
		return -1
	if p['s'] > q['s']:
		return 1
	if p['g'] < q['g']:
		return -1
	return 1

def readgraph():
	# Read the number of vertices.
	n = int(input())
	# Allocate memory for the vertices and edges.
	g.vcnt = n
	g.ecnt = 2*n-2
	# Allocate memory for the edge array and sort it.
	g.e = [E for i in range(g.ecnt+10)]
	rep(i,0,n-1):
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
	g.e.sort(esort)
	# Initialize the id array.
	p = 0
	rep(i,0,g.vcnt):
		# Find the index of the current vertex in the sorted edge list.
		while p<g.ecnt and g.e[p].s<i:
			p += 1
		g.id.append(p)
	# Set the last index as a sentinel.
	g.id.append(g.ecnt)

def tyokkeidfs(s):
	# Iterate through the edges connected to the current vertex.
	for i in range(g.id[s],g.id[s+1]):
		# If the destination vertex has not been visited yet, recursively call tyokkeidfs.
		if tyokkeitemp[g.e[i].g]==0:
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
	rep(i,0,g.vcnt):
		# If the current vertex depth is greater than the maximum depth, update it.
		if tyokkeitemp[i]>M:
			M = tyokkeitemp[i]
			Mi = i
	# Free the memory allocated for tyokkeitemp.
	del tyokkeitemp
	# Return the diameter which is the maximum depth minus 1.
	return M-1

# Main function to read the graph and print the diameter.
def main():
	# Read the graph.
	readgraph()
	# Call the tyokkei function to find the diameter.
	print(tyokkei())
	# Free the memory allocated for the edge array.
	del g.e
	return 0

