# Depth-first search (DFS) with stack

# Read the number of nodes in the graph
N = int(input())

# Initialize a slice to hold the edges and an adjacency list for the graph
ab = [[0, 0] for i in range(N-1)]
edges = [[] for i in range(N)]

# Read edges from input and populate the adjacency list
for i in range(N-1):
	a = int(input()) - 1 # Convert to zero-based index
	b = int(input()) - 1 # Convert to zero-based index
	ab[i][0], ab[i][1] = a, b
	edges[a] = edges[a] + [b]
	edges[b] = edges[b] + [a]

# Map to store colors assigned to edges
colors = {}
# Stack for depth-first search (DFS) with current node, used color, and parent node
q = []
q.append([0, -1, -1]) # Start DFS from node 0 with no used color and no parent

# Perform DFS to assign colors to edges
while len(q)!= 0:
	currentNode, usedColor, parentNode = q.pop()
	color = 1 # Start coloring from color 1

	# Iterate through child nodes of the current node
	for childNode in edges[currentNode]:
		if childNode == parentNode:
			continue # Skip the parent node to avoid backtracking
		if color == usedColor:
			color = color + 1 # Skip the color that was used by the parent
		# Assign color to the edge between currentNode and childNode
		colors[genid(currentNode, childNode)] = color
		# Push the child node onto the stack for further exploration
		q.append([childNode, color, currentNode])
		color = color + 1 # Move to the next color for the next edge

# Find the maximum degree of any node in the graph
K = -1
for i in range(N):
	t = len(edges[i]) # Degree of the current node
	if t > K:
		K = t # Update maximum degree if current node's degree is greater

print(K) # Print the maximum degree

# Print the colors assigned to each edge
for i in range(N-1):
	print(colors[genid(ab[i][0], ab[i][1])])

# 