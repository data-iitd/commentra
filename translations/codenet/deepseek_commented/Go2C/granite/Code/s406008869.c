

#include <stdio.h>
#include <stdbool.h>

int n, m;
int **e;
bool *visited;

// Function to print the edges of the graph in a readable format
void printEdge(int **e) {
	for (int i = 1; i <= n; i++) {
		printf("%d: ", i);
		for (int j = 0; j < e[i][0]; j++) {
			printf("%d ", e[i][j+1]);
		}
		printf("\n");
	}
}

// Depth-First Search (DFS) function to count connected components in the graph
int dfs(int v) {
	// Mark the current node as visited
	// printf("%d ", v);

	// Check if all nodes are visited
	bool comp = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			comp = false;
		}
	}

	if (comp) {
		return 1;
	}

	int count = 0;
	for (int j = 1; j <= e[v][0]; j++) {
		int ne = e[v][j];
		if (visited[ne]) {
			continue;
		}
		visited[ne] = true;
		count += dfs(ne);
		visited[ne] = false;
	}
	return count;
}

// Main function to read input, initialize the graph, and perform DFS
int main() {
	scanf("%d %d", &n, &m);

	// Initialize the graph edges
	e = (int **)malloc(sizeof(int *) * (n + 1));
	for (int i = 1; i <= n; i++) {
		e[i] = (int *)malloc(sizeof(int) * (m + 1));
		e[i][0] = 0;
	}

	// Read the edges and populate the graph
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a][++e[a][0]] = b;
		e[b][++e[b][0]] = a;
	}
	// printEdge(e);

	// Initialize visited array and start DFS from node 1
	visited = (bool *)malloc(sizeof(bool) * (n + 1));
	visited[1] = true;
	int count = dfs(1);
	printf("%d\n", count);

	return 0;
}
