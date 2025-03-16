package main

import "fmt"

// Declare a global variable for the adjacency list representation of the graph
var e [][]int
// Declare variables for the number of nodes (n) and edges (m)
var n, m int

// Function to print the edges of the graph
func printEdge(e [][]int) {
	// Iterate through each node in the graph
	for i := 1; i < n+1; i++ {
		fmt.Printf("%d: ", i) // Print the node number
		// Print all adjacent nodes (edges) for the current node
		for _, v := range e[i] {
			fmt.Printf("%d ", v)
		}
		fmt.Println() // Move to the next line after printing all edges for the current node
	}
}

// Depth-first search (DFS) function to explore the graph
func dfs(v int, visited []bool) int {
	// Check if all nodes have been visited
	comp := true
	for i := 1; i < n+1; i++ {
		if !visited[i] {
			comp = false // If any node is not visited, set comp to false
		}
	}

	// If all nodes have been visited, return 1 (indicating a complete component)
	if comp {
		return 1
	}

	count := 0 // Initialize count of connected nodes
	// Explore all neighbors of the current node
	for _, ne := range e[v] {
		// Skip already visited nodes
		if visited[ne] {
			continue
		}
		visited[ne] = true // Mark the neighbor as visited
		// Recursively call DFS for the neighbor and accumulate the count
		rst := dfs(ne, visited)
		count += rst // Increment the count with the result from the DFS call
		visited[ne] = false // Backtrack: unmark the neighbor as visited
	}
	return count // Return the total count of connected nodes
}

func main() {
	// Read the number of nodes and edges from input
	fmt.Scan(&n, &m)

	// Initialize the adjacency list for the graph
	e = make([][]int, n+1)
	for i := 1; i < n+1; i++ {
		e[i] = make([]int, 0) // Create an empty slice for each node
	}
	// Read the edges and populate the adjacency list
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read each edge
		e[a] = append(e[a], b) // Add the edge to the adjacency list
		e[b] = append(e[b], a) // Since the graph is undirected, add both directions
	}
	// Uncomment to print the edges of the graph
	// printEdge(e)

	// Initialize the visited array to keep track of visited nodes
	visited := make([]bool, n+1)
	visited[1] = true // Mark the starting node (node 1) as visited
	count := dfs(1, visited) // Perform DFS starting from node 1
	fmt.Println(count) // Print the count of connected nodes
}
