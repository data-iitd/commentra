

#include <stdio.h>
#include <stdlib.h>

// Declare a global variable for the adjacency list representation of the graph
int **e;
// Declare variables for the number of nodes (n) and edges (m)
int n, m;

// Function to print the edges of the graph
void printEdge() {
	// Iterate through each node in the graph
	for (int i = 1; i < n+1; i++) {
		printf("%d: ", i); // Print the node number
		// Print all adjacent nodes (edges) for the current node
		for (int j = 0; j < e[i][0]; j++) {
			printf("%d ", e[i][j+1]);
		}
		printf("\n"); // Move to the next line after printing all edges for the current node
	}
}

// Depth-first search (DFS) function to explore the graph
int dfs(int v, bool *visited) {
	// Check if all nodes have been visited
	int comp = 1;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			comp = 0; // If any node is not visited, set comp to false
		}
	}

	// If all nodes have been visited, return 1 (indicating a complete component)
	if (comp) {
		return 1;
	}

	int count = 0; // Initialize count of connected nodes
	// Explore all neighbors of the current node
	for (int i = 1; i < e[v][0]; i++) {
		// Skip already visited nodes
		if (visited[e[v][i+1]]) {
			continue;
		}
		visited[e[v][i+1]] = true; // Mark the neighbor as visited
		// Recursively call DFS for the neighbor and accumulate the count
		int rst = dfs(e[v][i+1], visited);
		count += rst; // Increment the count with the result from the DFS call
		visited[e[v][i+1]] = false; // Backtrack: unmark the neighbor as visited
	}
	return count; // Return the total count of connected nodes
}

int main() {
	// Read the number of nodes and edges from input
	scanf("%d %d", &n, &m);

	// Initialize the adjacency list for the graph
	e = (int **)malloc((n+1) * sizeof(int *));
	for (int i = 1; i < n+1; i++) {
		e[i] = (int *)malloc((n+1) * sizeof(int)); // Create an empty slice for each node
		e[i][0] = 0; // Initialize the length of the slice to 0
	}
	// Read the edges and populate the adjacency list
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b); // Read each edge
		e[a][e[a][0]+1] = b; // Add the edge to the adjacency list
		e[b][e[b][0]+1] = a; // Since the graph is undirected, add both directions
		e[a][0]++; // Increment the length of the slice for node a
		e[b][0]++; // Increment the length of the slice for node b
	}
	// Uncomment to print the edges of the graph
	// printEdge();

	// Initialize the visited array to keep track of visited nodes
	bool *visited = (bool *)malloc((n+1) * sizeof(bool));
	for (int i = 1; i < n+1; i++) {
		visited[i] = false; // Mark all nodes as unvisited
	}
	visited[1] = true; // Mark the starting node (node 1) as visited
	int count = dfs(1, visited); // Perform DFS starting from node 1
	printf("%d\n", count); // Print the count of connected nodes
}

