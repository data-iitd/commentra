

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N = readInt();

	// Initialize a slice to hold the edges and an adjacency list for the graph
	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		ab[i][0] = readInt() - 1; // Convert to zero-based index
		ab[i][1] = readInt() - 1; // Convert to zero-based index
		edges[ab[i][0]] = (int *) realloc(edges[ab[i][0]], sizeof(int) * (i+2));
		edges[ab[i][0]][i] = ab[i][1];
		edges[ab[i][1]] = (int *) realloc(edges[ab[i][1]], sizeof(int) * (i+2));
		edges[ab[i][1]][i] = ab[i][0];
	}

	// Map to store colors assigned to edges
	int colors[N-1];
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	int q[N-1][3];
	int q_size = 0;
	q[q_size][0] = 0;
	q[q_size][1] = -1;
	q[q_size][2] = -1;
	q_size++;

	// Perform DFS to assign colors to edges
	while (q_size > 0) {
		int currentNode = q[q_size-1][0];
		int usedColor = q[q_size-1][1];
		int parentNode = q[q_size-1][2];
		q_size--;

		int color = 1; // Start coloring from color 1

		// Iterate through child nodes of the current node
		for (int i = 0; i < q_size; i++) {
			if (q[i][0] == parentNode) {
				continue; // Skip the parent node to avoid backtracking
			}
			if (color == usedColor) {
				color++; // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, q[i][0])] = color;
			// Push the child node onto the stack for further exploration
			q[q_size][0] = q[i][0];
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			color++; // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = q_size; // Degree of the current node
		if (t > K) {
			K = t; // Update maximum degree if current node's degree is greater
		}
	}
	printf("%d\n", K); // Print the maximum degree

	// Print the colors assigned to each edge
	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N = readInt();

	// Initialize a slice to hold the edges and an adjacency list for the graph
	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		ab[i][0] = readInt() - 1; // Convert to zero-based index
		ab[i][1] = readInt() - 1; // Convert to zero-based index
		edges[ab[i][0]] = (int *) realloc(edges[ab[i][0]], sizeof(int) * (i+2));
		edges[ab[i][0]][i] = ab[i][1];
		edges[ab[i][1]] = (int *) realloc(edges[ab[i][1]], sizeof(int) * (i+2));
		edges[ab[i][1]][i] = ab[i][0];
	}

	// Map to store colors assigned to edges
	int colors[N-1];
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	int q[N-1][3];
	int q_size = 0;
	q[q_size][0] = 0;
	q[q_size][1] = -1;
	q[q_size][2] = -1;
	q_size++;

	// Perform DFS to assign colors to edges
	while (q_size > 0) {
		int currentNode = q[q_size-1][0];
		int usedColor = q[q_size-1][1];
		int parentNode = q[q_size-1][2];
		q_size--;

		int color = 1; // Start coloring from color 1

		// Iterate through child nodes of the current node
		for (int i = 0; i < q_size; i++) {
			if (q[i][0] == parentNode) {
				continue; // Skip the parent node to avoid backtracking
			}
			if (color == usedColor) {
				color++; // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, q[i][0])] = color;
			// Push the child node onto the stack for further exploration
			q[q_size][0] = q[i][0];
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			color++; // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = q_size; // Degree of the current node
		if (t > K) {
			K = t; // Update maximum degree if current node's degree is greater
		}
	}
	printf("%d\n", K); // Print the maximum degree

	// Print the colors assigned to each edge
	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N = readInt();

	// Initialize a slice to hold the edges and an adjacency list for the graph
	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		ab[i][0] = readInt() - 1; // Convert to zero-based index
		ab[i][1] = readInt() - 1; // Convert to zero-based index
		edges[ab[i][0]] = (int *) realloc(edges[ab[i][0]], sizeof(int) * (i+2));
		edges[ab[i][0]][i] = ab[i][1];
		edges[ab[i][1]] = (int *) realloc(edges[ab[i][1]], sizeof(int) * (i+2));
		edges[ab[i][1]][i] = ab[i][0];
	}

	// Map to store colors assigned to edges
	int colors[N-1];
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	int q[N-1][3];
	int q_size = 0;
	q[q_size][0] = 0;
	q[q_size][1] = -1;
	q[q_size][2] = -1;
	q_size++;

	// Perform DFS to assign colors to edges
	while (q_size > 0) {
		int currentNode = q[q_size-1][0];
		int usedColor = q[q_size-1][1];
		int parentNode = q[q_size-1][2];
		q_size--;

		int color = 1; // Start coloring from color 1

		// Iterate through child nodes of the current node
		for (int i = 0; i < q_size; i++) {
			if (q[i][0] == parentNode) {
				continue; // Skip the parent node to avoid backtracking
			}
			if (color == usedColor) {
				color++; // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, q[i][0])] = color;
			// Push the child node onto the stack for further exploration
			q[q_size][0] = q[i][0];
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			color++; // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = q_size; // Degree of the current node
		if (t > K) {
			K = t; // Update maximum degree if current node's degree is greater
		}
	}
	printf("%d\n", K); // Print the maximum degree

	// Print the colors assigned to each edge
	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N = readInt();

	// Initialize a slice to hold the edges and an adjacency list for the graph
	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		ab[i][0] = readInt() - 1; // Convert to zero-based index
		ab[i][1] = readInt() - 1; // Convert to zero-based index
		edges[ab[i][0]] = (int *) realloc(edges[ab[i][0]], sizeof(int) * (i+2));
		edges[ab[i][0]][i] = ab[i][1];
		edges[ab[i][1]] = (int *) realloc(edges[ab[i][1]], sizeof(int) * (i+2));
		edges[ab[i][1]][i] = ab[i][0];
	}

	// Map to store colors assigned to edges
	int colors[N-1];
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	int q[N-1][3];
	int q_size = 0;
	q[q_size][0] = 0;
	q[q_size][1] = -1;
	q[q_size][2] = -1;
	q_size++;

	// Perform DFS to assign colors to edges
	while (q_size > 0) {
		int currentNode = q[q_size-1][0];
		int usedColor = q[q_size-1][1];
		int parentNode = q[q_size-1][2];
		q_size--;

		int color = 1; // Start coloring from color 1

		// Iterate through child nodes of the current node
		for (int i = 0; i < q_size; i++) {
			if (q[i][0] == parentNode) {
				continue; // Skip the parent node to avoid backtracking
			}
			if (color == usedColor) {
				color++; // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, q[i][0])] = color;
			// Push the child node onto the stack for further exploration
			q[q_size][0] = q[i][0];
			q[q_size][1] = color;
			q[q_size][2] = currentNode;
			q_size++;
			color++; // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = q_size; // Degree of the current node
		if (t > K) {
			K = t; // Update maximum degree if current node's degree is greater
		}
	}
	printf("%d\n", K); // Print the maximum degree

	// Print the colors assigned to each edge
	for (int i = 0; i < N-1; i++) {
		printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N = readInt();

	// Initialize a slice to hold the edges and an adjacency list for the graph
	int ab[N-1][2];
	int *edges[N];
	for (int i = 0; i < N-1; i++) {
		ab[i][0] = readInt() - 1;