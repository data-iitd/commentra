// 深さ優先探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate unique id based on two integers
int genid(int a, int b) {
	if (b < a) {
		a = b;
		b = a;
	}
	// Multiply the larger number by 100000 and add the smaller number
	return a*100000 + b;
}

// Main function
int main() {
	// Read the number of edges in the graph
	int N = 0;
	scanf("%d", &N);

	// Initialize an adjacency list and a 2D array to store the edges between nodes
	int ab[N-1][2];
	int **edges = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++) {
		edges[i] = (int *)malloc(N * sizeof(int));
		memset(edges[i], 0, N * sizeof(int));
	}
	for (int i = 0; i < N-1; i++) {
		// Read two integers representing the nodes connected by an edge
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		// Store the nodes and their indices in the ab array
		ab[i][0] = a-1;
		ab[i][1] = b-1;
		// Add the edge to the adjacency list
		edges[a-1][b-1] = 1;
		edges[b-1][a-1] = 1;
	}

	// Initialize a map to store the colors of each connected component
	int colors[N*N];
	// Initialize a queue to perform DFS
	int q[N*N][3];
	// Add the first node to the queue with initial color and parent node set to -1
	q[0][0] = 0;
	q[0][1] = -1;
	q[0][2] = -1;
	int q_size = 1;
	for (int i = 0; i < q_size; i++) {
		// Dequeue the current node, its color, and its parent node
		int currentNode = q[i][0];
		int usedColor = q[i][1];
		int parentNode = q[i][2];
		// Set the color of the current node to the next available color
		int color = 1;
		for (int j = 0; j < N; j++) {
			if (edges[currentNode][j] == 0 || j == parentNode) {
				continue;
			}
			// If the color of the current node is the same as the color of the child node, increment the color
			if (color == usedColor) {
				color++;
			}
			// Assign the color to the child node and add it to the queue with the current node as its parent node
			colors[genid(currentNode, j)] = color;
			q[q_size][0] = j;
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			// Increment the color for the next iteration
			color++;
		}
	}

	// Initialize a variable to store the maximum number of edges in a connected component
	int K = -1;
	// Iterate through all nodes in the graph and update the maximum number of edges if necessary
	for (int i = 0; i < N; i++) {
		int t = 0;
		for (int j = 0; j < N; j++) {
			if (edges[i][j] == 1) {
				t++;
			}
		}
		if (t > K) {
			K = t;
		}
	}
	// Print the maximum number of edges in a connected component
	printf("%d\n", K);

	// Iterate through all edges in the graph and print their colors
	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}

	// Free the memory allocated for the adjacency list
	for (int i = 0; i < N; i++) {
		free(edges[i]);
	}
	free(edges);

	return 0;
}

