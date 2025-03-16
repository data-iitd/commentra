
#include <stdio.h>
#include <stdlib.h>

// Define a 2D array 'e' to store the edges of the graph
int **e;

// Define variables 'n' and 'm' to store the number of nodes and edges respectively
int n, m;

// Function 'printEdge' to print the edges of the graph
void printEdge(int **e) {
	// Iterate through each node in the graph
	for (int i = 1; i < n+1; i++) {
		// Print the node number and its connected nodes
		printf("%d: ", i);
		for (int j = 0; j < m; j++) {
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
}

// Function 'dfs' to perform Depth First Search traversal
int dfs(int v, int *visited) {
	// Initialize a boolean array 'visited' to keep track of visited nodes
	// visited[v] = true
	// printf("%d, ", v);

	// Check if all nodes are visited, if yes then it's a strongly connected component
	int comp = 1;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			comp = 0;
			break;
		}
	}

	// If all nodes are visited, return 1 for this strongly connected component
	if (comp) {
		return 1;
	}

	// Initialize a counter 'count' to store the size of the strongly connected component
	int count = 0;
	// Iterate through the neighbors of the current node 'v'
	for (int i = 0; i < m; i++) {
		// If the neighbor is already visited, skip it
		if (visited[e[v][i]]) {
			continue;
		}
		// Mark the neighbor as visited
		visited[e[v][i]] = true;
		// Recursively call 'dfs' on the neighbor and add its size to the counter
		// rst := dfs(ne, visited, count)
		// count += rst
		count += dfs(e[v][i], visited);
		// Mark the neighbor as unvisited
		visited[e[v][i]] = false;
	}
	// Return the size of the strongly connected component
	return count;
}

// Function 'main' to read input and call the 'printEdge' and 'dfs' functions
int main() {
	// Read the number of nodes and edges from the standard input
	scanf("%d %d", &n, &m);

	// Initialize a 2D array 'e' of size (n+1)x(n+1) to store the edges of the graph
	e = (int **)malloc((n+1) * sizeof(int *));
	for (int i = 1; i < n+1; i++) {
		// Initialize an empty array for each node
		e[i] = (int *)malloc(m * sizeof(int));
	}
	// Read the edges of the graph from the standard input and add them to the 'e' array
	for (int i = 0; i < m; i++) {
		int a, b;
		// Read the nodes of an edge from the standard input
		scanf("%d %d", &a, &b);
		// Add the edge to the 'e' array for both nodes
		e[a][i] = b;
		e[b][i] = a;
	}
	// Call the 'printEdge' function to print the edges of the graph
	// printEdge(e)

	// Initialize a boolean array 'visited' of size (n+1) to keep track of visited nodes
	int *visited = (int *)malloc((n+1) * sizeof(int));
	// Mark the first node as visited
	visited[1] = true;
	// Call the 'dfs' function on the first node and print the size of the strongly connected component
	int count = dfs(1, visited);
	printf("%d\n", count);
	return 0;
}

