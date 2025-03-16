
#include <stdio.h>
#include <stdlib.h>

int n, m;
int **e;

// Function to print the edges of the graph in a readable format
void printEdge(int **e) {
	for (int i = 1; i < n + 1; i++) {
		printf("%d: ", i);
		for (int j = 0; j < m; j++) {
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
}

// Depth-First Search (DFS) function to count connected components in the graph
int dfs(int v, int *visited) {
	// Mark the current node as visited
	// printf("%d, ", v);

	// Check if all nodes are visited
	int comp = 1;
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			comp = 0;
		}
	}

	if (comp) {
		return 1;
	}

	int count = 0;
	for (int i = 0; i < m; i++) {
		if (visited[e[v][i]]) {
			continue;
		}
		visited[e[v][i]] = 1;
		count += dfs(e[v][i], visited);
		visited[e[v][i]] = 0;
	}
	return count;
}

// Main function to read input, initialize the graph, and perform DFS
int main() {
	scanf("%d %d", &n, &m);

	// Initialize the graph edges
	e = (int **)malloc((n + 1) * sizeof(int *));
	for (int i = 1; i < n + 1; i++) {
		e[i] = (int *)malloc(m * sizeof(int));
	}

	// Read the edges and populate the graph
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a][i] = b;
		e[b][i] = a;
	}
	// printEdge(e);

	// Initialize visited slice and start DFS from node 1
	int *visited = (int *)malloc((n + 1) * sizeof(int));
	for (int i = 1; i < n + 1; i++) {
		visited[i] = 0;
	}
	visited[1] = 1;
	int count = dfs(1, visited);
	printf("%d\n", count);
	return 0;
}

