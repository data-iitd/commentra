
#include <iostream>
#include <vector>
#include <map>
#include <cassert>

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		std::swap(a, b);
	}
	return a*100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N = readInt();

	// Initialize a vector to hold the edges and an adjacency list for the graph
	std::vector<std::vector<int>> edges(N);
	std::vector<std::pair<int, int>> ab(N-1);

	// Read edges from input and populate the adjacency list
	for (int i = 0; i < N-1; i++) {
		int a = readInt() - 1; // Convert to zero-based index
		int b = readInt() - 1; // Convert to zero-based index
		ab[i] = {a, b};
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// Map to store colors assigned to edges
	std::map<int, int> colors;
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	std::vector<std::tuple<int, int, int>> q;
	q.push_back({0, -1, -1}); // Start DFS from node 0 with no used color and no parent

	// Perform DFS to assign colors to edges
	while (!q.empty()) {
		int currentNode, usedColor, parentNode;
		std::tie(currentNode, usedColor, parentNode) = q.back();
		q.pop_back();
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
			q.push_back({childNode, color, currentNode});
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
}

// Constants for input buffer size
const int ioBufferSize = 1 * 1024 * 1024; // 1 MB

// stdinScanner initializes a buffered scanner for reading input
std::unique_ptr<std::istringstream> stdinScanner = std::unique_ptr<std::istringstream>(new std::istringstream());

// readString reads a string from standard input
std::string readString() {
	std::getline(*stdinScanner, std::string());
	return stdinScanner->str();
}

// readInt reads an integer from standard input and handles any conversion errors
int readInt() {
	std::string inputString = readString();
	int result;
	try {
		result = std::stoi(inputString);
	} catch (std::invalid_argument const & e) {
		std::cout << "Error: Input is not an integer." << std::endl;
		exit(1);
	}
	return result;
}

