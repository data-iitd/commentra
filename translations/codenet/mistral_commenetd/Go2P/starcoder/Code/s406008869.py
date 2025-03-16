# Package main is the entry point of the program
import sys

# Define a 2D slice 'e' to store the edges of the graph
e = []

# Define variables 'n' and'm' to store the number of nodes and edges respectively
n = 0
m = 0

# Function 'printEdge' to print the edges of the graph
def printEdge(e):
	# Iterate through each node in the graph
	for i in range(1, n+1):
		# Print the node number and its connected nodes
		print(i, ":", end=" ")
		for v in e[i]:
			print(v, end=" ")
		print()

# Function 'dfs' to perform Depth First Search traversal
def dfs(v, visited):
	# Initialize a boolean slice 'visited' to keep track of visited nodes
	# visited[v] = True
	# print(v, visited)

	# Check if all nodes are visited, if yes then it's a strongly connected component
	comp = True
	for i in range(1, n+1):
		if not visited[i]:
			comp = False
			break

	# If all nodes are visited, return 1 for this strongly connected component
	if comp:
		return 1

	# Initialize a counter 'count' to store the size of the strongly connected component
	count = 0
	# Iterate through the neighbors of the current node 'v'
	for ne in e[v]:
		# If the neighbor is already visited, skip it
		if visited[ne]:
			continue
		# Mark the neighbor as visited
		visited[ne] = True
		# Recursively call 'dfs' on the neighbor and add its size to the counter
		# rst = dfs(ne, visited, count)
		# count += rst
		rst = dfs(ne, visited)
		count += rst
		# Mark the neighbor as unvisited
		visited[ne] = False
	# Return the size of the strongly connected component
	return count

# Function'main' to read input and call the 'printEdge' and 'dfs' functions
def main():
	# Read the number of nodes and edges from the standard input
	n, m = map(int, input().split())

	# Initialize a 2D slice 'e' of size (n+1)x(n+1) to store the edges of the graph
	e = [[] for i in range(n+1)]
	# Read the edges of the graph from the standard input and add them to the 'e' slice
	for i in range(m):
		a, b = map(int, input().split())
		# Add the edge to the 'e' slice for both nodes
		e[a] = e[a] + [b]
		e[b] = e[b] + [a]
	# Call the 'printEdge' function to print the edges of the graph
	# printEdge(e)

	# Initialize a boolean slice 'visited' of size (n+1) to keep track of visited nodes
	visited = [False for i in range(n+1)]
	# Mark the first node as visited
	visited[1] = True
	# Call the 'dfs' function on the first node and print the size of the strongly connected component
	count = dfs(1, visited)
	print(count)

# Call the main function
if __name__ == "__main__":
	main()

# 