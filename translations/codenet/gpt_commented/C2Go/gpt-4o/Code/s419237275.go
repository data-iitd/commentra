package main

import (
	"fmt"
)

const (
	N    = 200 // Maximum number of nodes
	SHIRO = 0  // Color constant for unvisited nodes
	HAI   = 1  // Color constant for visiting nodes
	KURO  = 2  // Color constant for visited nodes
)

var (
	n     int                // Number of nodes
	A     [N][N]int          // Adjacency matrix
	color [N]int             // Array to store colors
	d     [N]int             // Array to store discovery times
	f     [N]int             // Array to store finishing times
	TT    int                // Global variable to keep track of time during DFS
)

func main() {
	var u, k, v int // Variables for input: u = node, k = number of edges, v = adjacent node

	// Read the number of nodes
	fmt.Scan(&n)

	// Initialize the adjacency matrix to zero (no edges)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			A[i][j] = 0
		}
	}

	// Read the edges for each node
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k) // Read node u and number of edges k
		u--              // Convert to zero-based index
		for j := 0; j < k; j++ {
			fmt.Scan(&v) // Read each adjacent node v
			v--          // Convert to zero-based index
			A[u][v] = 1  // Mark the edge in the adjacency matrix
		}
	}

	// Call the DFS function to process the graph
	aaaaa()
}

// Function to perform DFS and initialize variables
func aaaaa() {
	// Initialize all nodes to unvisited (SHIRO)
	for i := 0; i < n; i++ {
		color[i] = SHIRO
	}

	TT = 0 // Reset the time counter

	// Perform DFS for each unvisited node
	for u := 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbb(u) // Call DFS for the unvisited node
		}
	}

	// Print the discovery and finishing times for each node
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i]) // Output format: node index, discovery time, finishing time
	}
}

// Recursive function to visit nodes in DFS
func bbbbb(k int) {
	color[k] = HAI // Mark the current node as visiting (HAI)
	TT++           // Increment the time counter
	d[k] = TT      // Set the discovery time for the current node

	// Visit all adjacent nodes
	for v := 0; v < n; v++ {
		if A[k][v] == 0 {
			continue // Skip if there is no edge
		}
		if color[v] == SHIRO { // If the adjacent node is unvisited
			bbbbb(v) // Recursively visit the adjacent node
		}
	}

	color[k] = KURO // Mark the current node as visited (KURO)
	f[k] = TT + 1   // Set the finishing time for the current node
	TT++            // Increment the time counter
}

// <END-OF-CODE>
