
import sys

e = {}
n, m = map(int, input().split())

# Function to print the edges of the graph in a readable format
def printEdge(e):
	for i in range(1, n+1):
		print(i, e[i])

# Depth-First Search (DFS) function to count connected components in the graph
def dfs(v, visited):
	# Mark the current node as visited
	# print(v, visited)

	# Check if all nodes are visited
	comp = True
	for i in range(1, n+1):
		if not visited[i]:
			comp = False
	if comp:
		return 1

	count = 0
	for ne in e[v]:
		# print("ne=", ne)
		if visited[ne]:
			continue
		visited[ne] = True
		# if cmp, _ := dfs(ne, visited, count); cmp:
		# 	count += 1
		# else:
		# 	count += dfs(ne, visited)
		count += dfs(ne, visited)
		visited[ne] = False
	return count

# Main function to read input, initialize the graph, and perform DFS
def main():
	for i in range(1, n+1):
		e[i] = []
	for i in range(m):
		a, b = map(int, input().split())
		e[a] = e[a] + [b]
		e[b] = e[b] + [a]
	# printEdge(e)

	# Initialize visited slice and start DFS from node 1
	visited = [False] * (n+1)
	visited[1] = True
	count = dfs(1, visited)
	print(count)

if __name__ == "__main__":
	main()

