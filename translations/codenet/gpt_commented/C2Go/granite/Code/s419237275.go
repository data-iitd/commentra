
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	SHIRO = 0 // Color constant for unvisited nodes
	HAI    = 1 // Color constant for visiting nodes
	KURO   = 2 // Color constant for visited nodes
)

// Function prototypes
func aaaaa() { // Function to perform depth-first search (DFS) and print discovery and finishing times
	var u, k, v int
	var i int

	// Initialize all nodes to unvisited (SHIRO)
	for i = 0; i < n; i++ {
		color[i] = SHIRO
	}

	TT = 0 // Reset the time counter

	// Perform DFS for each unvisited node
	for u = 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbb(u) // Call DFS for the unvisited node
		}
	}

	// Print the discovery and finishing times for each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i]) // Output format: node index, discovery time, finishing time
	}
}

func bbbbb(k int) { // Recursive function to visit nodes in DFS
	var v int
	color[k] = HAI // Mark the current node as visiting (HAI)
	TT++           // Increment the time counter
	d[k] = TT      // Set the discovery time for the current node

	// Visit all adjacent nodes
	for v = 0; v < n; v++ {
		if A[k][v] == 0 {
			continue // Skip if there is no edge
		}
		if color[v] == SHIRO { // If the adjacent node is unvisited
			bbbbb(v) // Recursively visit the adjacent node
		}
	}

	color[k] = KURO // Mark the current node as visited (KURO)
	f[k] = TT + 1   // Set the finishing time for the current node
}

func main() {
	var u, k, v int
	var i, j int

	// Read the number of nodes
	fmt.Scan(&n)

	// Initialize the adjacency matrix to zero (no edges)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			A[i][j] = 0
		}
	}

	// Read the edges for each node
	for i = 0; i < n; i++ {
		fmt.Scan(&u, &k) // Read node u and number of edges k
		u--                // Convert to zero-based index
		for j = 0; j < k; j++ {
			fmt.Scan(&v) // Read each adjacent node v
			v--            // Convert to zero-based index
			A[u][v] = 1   // Mark the edge in the adjacency matrix
		}
	}

	// Call the DFS function to process the graph
	aaaaa()

	// 