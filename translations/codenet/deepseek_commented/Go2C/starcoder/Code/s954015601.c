// 深さ優先探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes.
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes from standard input.
	int N = readInt();

	// Initialize a slice to store edges and an adjacency list for the graph.
	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		// Read edge information and populate the adjacency list.
		int a = readInt() - 1;
		int b = readInt() - 1;
		ab[i][0] = a;
		ab[i][1] = b;
		edges[a] = (int *) realloc(edges[a], sizeof(int) * (1 + (edges[a]? (int) (sizeof(edges[a]) / sizeof(int)) : 0)));
		edges[a][(edges[a]? (int) (sizeof(edges[a]) / sizeof(int)) : 0)] = b;
		edges[b] = (int *) realloc(edges[b], sizeof(int) * (1 + (edges[b]? (int) (sizeof(edges[b]) / sizeof(int)) : 0)));
		edges[b][(edges[b]? (int) (sizeof(edges[b]) / sizeof(int)) : 0)] = a;
	}

	// Initialize a map to store the color of each edge and a queue for DFS traversal.
	int colors[N-1];
	int q[N-1][3];
	q[0][0] = 0;
	q[0][1] = -1;
	q[0][2] = -1;
	int q_size = 1;
	for (int i = 0; i < q_size; i++) {
		// Pop the last element from the queue for DFS traversal.
		int currentNode = q[i][0];
		int usedColor = q[i][1];
		int parentNode = q[i][2];
		int color = 1;
		for (int j = 0; j < (edges[currentNode]? (int) (sizeof(edges[currentNode]) / sizeof(int)) : 0); j++) {
			int childNode = edges[currentNode][j];
			if (childNode == parentNode) {
				continue;
			}
			if (color == usedColor) {
				color++;
			}
			colors[genid(currentNode, childNode)] = color;
			q[q_size][0] = childNode;
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			color++;
		}
	}

	// Determine the maximum degree of any node in the graph.
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = (edges[i]? (int) (sizeof(edges[i]) / sizeof(int)) : 0);
		if (t > K) {
			K = t;
		}
	}
	printf("%d\n", K);

	// Output the colors of the edges.
	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}
}

int readInt() {
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	int result = atoi(line);
	free(line);
	return result;
}

