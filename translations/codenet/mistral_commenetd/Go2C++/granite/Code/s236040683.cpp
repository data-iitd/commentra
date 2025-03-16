
// Package main is the entry point of the program.
#include <iostream> // We use iostream package for formatted I/O.
#include <vector> // We use vector package for dynamic arrays.
#include <string> // We use string package for strings.
#include <sstream> // We use stringstream package for string conversion.

// out is a custom function for printing output.
void out(std::vector<std::string> x) {
	for (auto i : x) {
		std::cout << i << std::endl;
	}
}

// main is the entry point of the program.
int main() {
	// Read the number of nodes N and edges M from the input.
	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	int N, M;
	ss >> N >> M;

	// Create a vector n of size N to store the nodes.
	std::vector<std::vector<int>> n(N);

	// Process each edge by adding it to the to slice of the corresponding nodes.
	for (int i = 0; i < M; i++) {
		// Read the from and to nodes from the input.
		std::getline(std::cin, line);
		ss.clear();
		ss.str(line);
		int from, to;
		ss >> from >> to;
		from--;
		to--;

		// Add the edge to the to slice of the from node.
		n[from].push_back(to);

		// Add the edge to the to slice of the to node.
		n[to].push_back(from);
	}

	// Print the number of neighbors for each node.
	for (int i = 0; i < N; i++) {
		// Print the number of neighbors of the current node.
		std::cout << n[i].size() << std::endl;
	}
}

// 