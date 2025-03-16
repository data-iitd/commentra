package main

import (
	"fmt"
)

const (
	N    = 200 // Maximum number of nodes in the graph
	SHIRO = 0  // Color representing unvisited nodes
	HAI   = 1  // Color representing nodes currently in the recursion stack
	KURO  = 2  // Color representing nodes fully processed
)

var (
	n     int                // Number of nodes
	A     [N][N]int          // Adjacency matrix
	color [N]int             // Color of each node
	d     [N]int             // Discovery time
	f     [N]int             // Finish time
	TT    int                // Time counter
)

func main() {
	var u, k, v int // u: current node, k: number of edges from u, v: adjacent node

	// Read the number of nodes
	fmt.Scan(&n)

	// Initialize the adjacency matrix to zero
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			A[i][j] = 0
		}
	}

	// Read the edges for each node and update the adjacency matrix
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k)
		u-- // Adjust for 0-based indexing
		for j := 0; j < k; j++ {
			fmt.Scan(&v)
			v-- // Adjust for 0-based indexing
			A[u][v] = 1
		}
	}

	// Perform DFS and print the results
	aaaaa()
}

// Depth-First Search (DFS) function
func aaaaa() {
	// Initialize all nodes to "SHIRO" (unvisited)
	for i := 0; i < n; i++ {
		color[i] = SHIRO
	}

	// Set the time counter to zero
	TT = 0

	// Iterate over all nodes and perform DFS if the node is "SHIRO"
	for u := 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbb(u)
		}
	}

	// Print the discovery and finish times for each node
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

// Recursive DFS function
func bbbbb(k int) {
	// Set the current node's color to "HAI" (currently in the recursion stack)
	color[k] = HAI
	// Increment the time counter and record the discovery time
	TT++
	d[k] = TT

	// Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
	for v := 0; v < n; v++ {
		if A[k][v] == 0 {
			continue // Skip if no edge between k and v
		}
		if color[v] == SHIRO {
			bbbbb(v)
		}
	}

	// Set the current node's color to "KURO" (fully processed)
	color[k] = KURO
	// Record the finish time
	f[k] = TT + 1
	TT++
}

// <END-OF-CODE>
