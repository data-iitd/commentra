// Package main is the entry point of the program
#include <iostream>
#include <vector>

// Define a 2D vector 'e' to store the edges of the graph
std::vector<std::vector<int>> e;

// Define variables 'n' and 'm' to store the number of nodes and edges respectively
int n, m;

// Function 'printEdge' to print the edges of the graph
void printEdge(std::vector<std::vector<int>> e) {
	// Iterate through each node in the graph
	for (int i = 1; i < n+1; i++) {
		// Print the node number and its connected nodes
		std::cout << i << ": ";
		for (int j = 0; j < e[i].size(); j++) {
			std::cout << e[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Function 'dfs' to perform Depth First Search traversal
int dfs(int v, std::vector<bool> visited) {
	// Initialize a boolean vector 'visited' to keep track of visited nodes
	// visited[v] = true
	// std::cout << v << " " << visited << std::endl;

	// Check if all nodes are visited, if yes then it's a strongly connected component
	bool comp = true;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			comp = false;
			break;
		}
	}

	// If all nodes are visited, return 1 for this strongly connected component
	if (comp) {
		return 1;
	}

	// Initialize a counter 'count' to store the size of the strongly connected component
	int count = 0;
	// Iterate through the neighbors of the current node 'v'
	for (int i = 0; i < e[v].size(); i++) {
		// If the neighbor is already visited, skip it
		if (visited[e[v][i]]) {
			continue;
		}
		// Mark the neighbor as visited
		visited[e[v][i]] = true;
		// Recursively call 'dfs' on the neighbor and add its size to the counter
		// int rst = dfs(e[v][i], visited, count);
		// count += rst;
		int rst = dfs(e[v][i], visited);
		count += rst;
		// Mark the neighbor as unvisited
		visited[e[v][i]] = false;
	}
	// Return the size of the strongly connected component
	return count;
}

// Function 'main' to read input and call the 'printEdge' and 'dfs' functions
int main() {
	// Read the number of nodes and edges from the standard input
	std::cin >> n >> m;

	// Initialize a 2D vector 'e' of size (n+1)x(n+1) to store the edges of the graph
	e = std::vector<std::vector<int>>(n+1, std::vector<int>(0));
	// Read the edges of the graph from the standard input and add them to the 'e' vector
	for (int i = 0; i < m; i++) {
		int a, b;
		// Read the nodes of an edge from the standard input
		std::cin >> a >> b;
		// Add the edge to the 'e' vector for both nodes
		e[a].push_back(b);
		e[b].push_back(a);
	}
	// Call the 'printEdge' function to print the edges of the graph
	// printEdge(e);

	// Initialize a boolean vector 'visited' of size (n+1) to keep track of visited nodes
	std::vector<bool> visited(n+1, false);
	// Mark the first node as visited
	visited[1] = true;
	// Call the 'dfs' function on the first node and print the size of the strongly connected component
	int count = dfs(1, visited);
	std::cout << count << std::endl;
	return 0;
}

