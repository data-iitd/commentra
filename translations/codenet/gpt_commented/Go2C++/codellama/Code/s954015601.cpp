// 深さ優先探索
#include <iostream>
#include <vector>
#include <map>
#include <stack>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
		b = a;
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N;
	std::cin >> N;

	// Initialize a vector to hold the edges and an adjacency list for the graph
	std::vector<std::vector<int>> edges(N);
	std::vector<std::pair<int, int>> ab(N-1);

	// Read edges from input and populate the adjacency list
	for (int i = 0; i < N-1; i++) {
		int a, b;
		std::cin >> a >> b;
		ab[i].first = a-1; // Convert to zero-based index
		ab[i].second = b-1; // Convert to zero-based index
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}

	// Map to store colors assigned to edges
	std::map<int, int> colors;
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	std::stack<std::tuple<int, int, int>> q;
	q.push(std::make_tuple(0, -1, -1)); // Start DFS from node 0 with no used color and no parent

	// Perform DFS to assign colors to edges
	while (!q.empty()) {
		int currentNode, usedColor, parentNode;
		std::tie(currentNode, usedColor, parentNode) = q.top();
		q.pop();
		int color = 1; // Start coloring from color 1

		// Iterate through child nodes of the current node
		for (int childNode : edges[currentNode]) {
			if (childNode == parentNode) {
				continue; // Skip the parent node to avoid backtracking
			}
			if (color == usedColor) {
				color++; // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, childNode)] = color;
			// Push the child node onto the stack for further exploration
			q.push(std::make_tuple(childNode, color, currentNode));
			color++; // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = edges[i].size(); // Degree of the current node
		if (t > K) {
			K = t; // Update maximum degree if current node's degree is greater
		}
	}
	std::cout << K << std::endl; // Print the maximum degree

	// Print the colors assigned to each edge
	for (int i = 0; i < N-1; i++) {
		std::cout << colors[genid(ab[i].first, ab[i].second)] << std::endl;
	}

	return 0;
}

