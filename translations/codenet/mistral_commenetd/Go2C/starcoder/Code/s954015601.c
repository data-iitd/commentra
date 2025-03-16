// 深さ優先探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate unique id based on two integers
int genid(int a, int b) {
	if (b < a) {
		a = b;
	}
	// Multiply the larger number by 100000 and add the smaller number
	return a*100000 + b;
}

// Main function
int main() {
	// Read the number of edges in the graph
	int N = readInt();

	// Initialize an adjacency list and a 2D array to store the edges between nodes
	int ab[N-1][2];
	int **edges = (int **)malloc(sizeof(int *) * N);
	for (int i = 0; i < N-1; i++) {
		// Read two integers representing the nodes connected by an edge
		int a = readInt() - 1;
		int b = readInt() - 1;
		// Store the nodes and their indices in the ab array
		ab[i][0] = a;
		ab[i][1] = b;
		// Add the edge to the adjacency list
		edges[a] = (int *)realloc(edges[a], sizeof(int) * (1 + (edges[a]? (int)sizeof(edges[a]) / sizeof(int) : 0)));
		edges[a][(edges[a]? (int)sizeof(edges[a]) / sizeof(int) : 0)] = b;
		edges[b] = (int *)realloc(edges[b], sizeof(int) * (1 + (edges[b]? (int)sizeof(edges[b]) / sizeof(int) : 0)));
		edges[b][(edges[b]? (int)sizeof(edges[b]) / sizeof(int) : 0)] = a;
	}

	// Initialize a map to store the colors of each connected component
	int *colors = (int *)malloc(sizeof(int) * (N-1));
	// Initialize a queue to perform DFS
	int q[N-1][3];
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
		for (int j = 0; j < (edges[currentNode]? (int)sizeof(edges[currentNode]) / sizeof(int) : 0); j++) {
			int childNode = edges[currentNode][j];
			if (childNode == parentNode) {
				continue;
			}
			// If the color of the current node is the same as the color of the child node, increment the color
			if (color == usedColor) {
				color++;
			}
			// Assign the color to the child node and add it to the queue with the current node as its parent node
			colors[genid(currentNode, childNode)] = color;
			q[q_size][0] = childNode;
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
		int t = (edges[i]? (int)sizeof(edges[i]) / sizeof(int) : 0);
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
}

// Constants for input buffer size and standard input scanner
#define ioBufferSize 1 * 1024 * 1024 // 1 MB

// Function to read from standard input using a pre-initialized scanner
char *readString() {
	static char input_buffer[ioBufferSize];
	static char *input_buffer_pointer = input_buffer;
	static char *input_buffer_end = input_buffer;
	if (input_buffer_pointer == input_buffer_end) {
		fread(input_buffer, 1, ioBufferSize, stdin);
		input_buffer_pointer = input_buffer;
		input_buffer_end = input_buffer + ioBufferSize;
	}
	char *result = input_buffer_pointer;
	input_buffer_pointer++;
	return result;
}

// Function to read a single integer from standard input
int readInt() {
	char *next;
	int result;
	do {
		next = readString();
	} while (*next =='' || *next == '\n' || *next == '\r' || *next == '\t');
	result = atoi(next);
	return result;
}

