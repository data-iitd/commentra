
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

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
	vector<vector<int>> ab(N-1, vector<int>(2, 0));
	vector<vector<int>> edges(N, vector<int>());
	for (int i = 0; i < N-1; i++) {
		// Read two integers representing the nodes connected by an edge
		int a = readInt() - 1;
		int b = readInt() - 1;
		// Store the nodes and their indices in the ab array
		ab[i][0] = a;
		ab[i][1] = b;
		// Add the edge to the adjacency list
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// Initialize a map to store the colors of each connected component
	map<int, int> colors;
	// Initialize a queue to perform DFS
	queue<vector<int>> q;
	// Add the first node to the queue with initial color and parent node set to -1
	q.push(vector<int>{0, -1, -1});
	while (!q.empty()) {
		// Dequeue the current node, its color, and its parent node
		vector<int> currentNode = q.front();
		q.pop();
		int currentNodeIdx = currentNode[0];
		int usedColor = currentNode[1];
		int parentNodeIdx = currentNode[2];
		// Set the color of the current node to the next available color
		int color = 1;
		for (int childNodeIdx : edges[currentNodeIdx]) {
			if (childNodeIdx == parentNodeIdx) {
				continue;
			}
			// If the color of the current node is the same as the color of the child node, increment the color
			if (color == usedColor) {
				color++;
			}
			// Assign the color to the child node and add it to the queue with the current node as its parent node
			colors[genid(currentNodeIdx, childNodeIdx)] = color;
			q.push(vector<int>{childNodeIdx, color, currentNodeIdx});
			// Increment the color for the next iteration
			color++;
		}
	}

	// Initialize a variable to store the maximum number of edges in a connected component
	int K = -1;
	// Iterate through all nodes in the graph and update the maximum number of edges if necessary
	for (int i = 0; i < N; i++) {
		int t = edges[i].size();
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
const int ioBufferSize = 1 * 1024 * 1024; // 1 MB

// Function to read from standard input using a pre-initialized scanner
istream* inputStream = &cin;

// Function to read a single string from standard input
string readString() {
	string result;
	getline(*inputStream, result);
	return result;
}

// Function to read a single integer from standard input
int readInt() {
	string input = readString();
	int result;
	stringstream ss;
	ss << input;
	ss >> result;
	return result;
}

