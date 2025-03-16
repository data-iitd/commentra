package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	A [200][200]int
	color [200]int
	d [200]int
	f [200]int
	TT int
)

func main() {
	var (
		u, k, v int
	)
	var i, j int

	// Read the number of nodes
	fmt.Scanf("%d", &n)

	// Initialize the adjacency matrix to zero (no edges)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			A[i][j] = 0
		}
	}

	// Read the edges for each node
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d", &u, &k) // Read node u and number of edges k
		u-- // Convert to zero-based index
		for j = 0; j < k; j++ {
			fmt.Scanf("%d", &v) // Read each adjacent node v
			v-- // Convert to zero-based index
			A[u][v] = 1 // Mark the edge in the adjacency matrix
		}
	}

	// Call the DFS function to process the graph
	aaaaa()

	return
}

// Function to perform DFS and initialize variables
func aaaaa() {
	var (
		u, i int
	)

	// Initialize all nodes to unvisited (SHIRO)
	for i = 0; i < n; i++ {
		color[i] = 0
	}

	TT = 0 // Reset the time counter

	// Perform DFS for each unvisited node
	for u = 0; u < n; u++ {
		if color[u] == 0 {
			bbbbb(u) // Call DFS for the unvisited node
		}
	}

	// Print the discovery and finishing times for each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i]) // Output format: node index, discovery time, finishing time
	}
}

// Recursive function to visit nodes in DFS
func bbbbb(k int) {
	var (
		v int
	)
	color[k] = 1 // Mark the current node as visiting (HAI)
	TT++ // Increment the time counter
	d[k] = TT // Set the discovery time for the current node

	// Visit all adjacent nodes
	for v = 0; v < n; v++ {
		if A[k][v] == 0 {
			continue
		}
		if color[v] == 0 { // If the adjacent node is unvisited
			bbbbb(v) // Recursively visit the adjacent node
		}
	}

	color[k] = 2 // Mark the current node as visited (KURO)
	f[k] = ++TT // Set the finishing time for the current node
}

