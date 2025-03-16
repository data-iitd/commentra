// 深さ優先探索
#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
	std::cin >> N;

	// Initialize an adjacency list and a 2D array to store the edges between nodes
	std::vector<std::vector<int>> edges(N);
	std::vector<std::vector<int>> ab(N-1);
	for (int i = 0; i < N-1; i++) {
		// Read two integers representing the nodes connected by an edge
		int a = 0, b = 0;
		std::cin >> a >> b;
		// Store the nodes and their indices in the ab array
		ab[i][0] = a-1;
		ab[i][1] = b-1;
		// Add the edge to the adjacency list
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}

	// Initialize a map to store the colors of each connected component
	std::map<int, int> colors;
	// Initialize a queue to perform DFS
	std::queue<std::vector<int>> q;
	// Add the first node to the queue with initial color and parent node set to -1
	q.push(std::vector<int>{0, -1, -1});
	while (!q.empty()) {
		// Dequeue the current node, its color, and its parent node
		int currentNode = q.front()[0];
		int usedColor = q.front()[1];
		int parentNode = q.front()[2];
		q.pop();
		// Set the color of the current node to the next available color
		int color = 1;
		for (int childNode : edges[currentNode]) {
			if (childNode == parentNode) {
				continue;
			}
			// If the color of the current node is the same as the color of the child node, increment the color
			if (color == usedColor) {
				color++;
			}
			// Assign the color to the child node and add it to the queue with the current node as its parent node
			colors[genid(currentNode, childNode)] = color;
			q.push(std::vector<int>{childNode, color, currentNode});
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
	std::cout << K << std::endl;

	// Iterate through all edges in the graph and print their colors
	for (int i = 0; i < N-1; i++) {
		std::cout << colors[genid(ab[i][0], ab[i][1])] << std::endl;
	}

	return 0;
}

