
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	SHIRO = 0
	HAI    = 1
	KURO   = 2
)

var (
	n, TT int
	A      [200][200]int
	color  [200]int
	d, f   [200]int
)

func main() {
	var u, k, v int
	var i, j int

	// Read the number of nodes
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

	// Initialize the adjacency matrix to zero
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			A[i][j] = 0
		}
	}

	// Read the edges for each node and update the adjacency matrix
	for i = 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d", &u, &k)
		u-- // Adjust for 0-based indexing
		for j = 0; j < k; j++ {
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &v)
			v-- // Adjust for 0-based indexing
			A[u][v] = 1
		}
	}

	// Perform DFS and print the results
	aaaaa()

	// Print the discovery and finish times for each node
	for i = 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

// Depth-First Search (DFS) function
func aaaaaa() {
	var u, i int

	// Initialize all nodes to "SHIRO" (unvisited)
	for i = 0; i < n; i++ {
		color[i] = SHIRO
	}

	// Set the time counter to zero
	TT = 0

	// Iterate over all nodes and perform DFS if the node is "SHIRO"
	for u = 0; u < n; u++ {
		if color[u] == SHIRO {
			bbbbbb(u)
		}
	}
}

// Recursive DFS function
func bbbbbbb(k int) {
	var v int

	// Set the current node's color to "HAI" (currently in the recursion stack)
	color[k] = HAI
	// Increment the time counter and record the discovery time
	TT++
	d[k] = TT

	// Iterate over all nodes and perform DFS recursively if an adjacent node is "SHIRO"
	for v = 0; v < n; v++ {
		if A[k][v] == 0 {
			continue // Skip if no edge between k and v
		}
		if color[v] == SHIRO {
			bbbbbb(v)
		}
	}

	// Set the current node's color to "KURO" (fully processed)
	color[k] = KURO
	// Record the finish time
	f[k] = TT + 1
}

// END-OF-CODE