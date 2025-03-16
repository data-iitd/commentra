#include <iostream>
#include <vector>

using namespace std;

// Declare a global variable for the adjacency list representation of the graph
vector<vector<int>> e;
// Declare variables for the number of nodes (n) and edges (m)
int n, m;

// Function to print the edges of the graph
void printEdge(vector<vector<int>> e) {
	// Iterate through each node in the graph
	for (int i = 1; i < n+1; i++) {
		cout << i << ": "; // Print the node number
		// Print all adjacent nodes (edges) for the current node
		for (int v : e[i]) {
			cout << v << " ";
		}
		cout << endl; // Move to the next line after printing all edges for the current node
	}
}

// Depth-first search (DFS) function to explore the graph
int dfs(int v, vector<bool> &visited) {
	// Check if all nodes have been visited
	bool comp = true;
	for (int i = 1; i < n+1; i++) {
		if (!visited[i]) {
			comp = false; // If any node is not visited, set comp to false
		}
	}

	// If all nodes have been visited, return 1 (indicating a complete component)
	if (comp) {
		return 1;
	}

	int count = 0; // Initialize count of connected nodes
	// Explore all neighbors of the current node
	for (int ne : e[v]) {
		// Skip already visited nodes
		if (visited[ne]) {
			continue;
		}
		visited[ne] = true; // Mark the neighbor as visited
		// Recursively call DFS for the neighbor and accumulate the count
		int rst = dfs(ne, visited);
		count += rst; // Increment the count with the result from the DFS call
		visited[ne] = false; // Backtrack: unmark the neighbor as visited
	}
	return count; // Return the total count of connected nodes
}

int main() {
	// Read the number of nodes and edges from input
	cin >> n >> m;

	// Initialize the adjacency list for the graph
	e = vector<vector<int>>(n+1);
	for (int i = 1; i < n+1; i++) {
		e[i] = vector<int>(); // Create an empty vector for each node
	}
	// Read the edges and populate the adjacency list
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; // Read each edge
		e[a].push_back(b); // Add the edge to the adjacency list
		e[b].push_back(a); // Since the graph is undirected, add both directions
	}
	// Uncomment to print the edges of the graph
	// printEdge(e);

	// Initialize the visited array to keep track of visited nodes
	vector<bool> visited(n+1, false);
	visited[1] = true; // Mark the starting node (node 1) as visited
	int count = dfs(1, visited); // Perform DFS starting from node 1
	cout << count << endl; // Print the count of connected nodes
}

