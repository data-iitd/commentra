# Depth-first search
import sys

# Read the number of nodes from standard input.
N = int(sys.stdin.readline())

# Initialize a slice to store edges and an adjacency list for the graph.
ab = []
edges = [[] for i in range(N)]
for i in range(N-1):
	# Read edge information and populate the adjacency list.
	a, b = map(int, sys.stdin.readline().split())
	a -= 1
	b -= 1
	ab.append([a, b])
	edges[a].append(b)
	edges[b].append(a)

# Initialize a map to store the color of each edge and a queue for DFS traversal.
colors = {}
q = []
q.append([0, -1, -1])
while len(q)!= 0:
	# Pop the last element from the queue for DFS traversal.
	currentNode, usedColor, parentNode = q.pop()
	color = 1
	for childNode in edges[currentNode]:
		if childNode == parentNode:
			continue
		if color == usedColor:
			color += 1
		colors[genid(currentNode, childNode)] = color
		q.append([childNode, color, currentNode])
		color += 1

# Determine the maximum degree of any node in the graph.
K = -1
for i in range(N):
	t = len(edges[i])
	if t > K:
		K = t
print(K)

# Output the colors of the edges.
for i in range(N-1):
	print(colors[genid(ab[i][0], ab[i][1])])

# 