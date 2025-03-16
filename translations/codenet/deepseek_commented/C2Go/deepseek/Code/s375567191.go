package main

import (
	"fmt"
)

const (
	MAX  = 101
	WHITE = 0
	BLACK = 2
	GRAY  = 1
)

var (
	time int
	n    int
	g    [MAX][MAX]int
	d    [MAX]int
	f    [MAX]int
	color [MAX]int
)

// The visit function performs a depth-first search on the graph.
func visit(u int) {
	color[u] = GRAY  // Set the color of the current node to gray.
	d[u] = time + 1 // Record the discovery time.
	time++

	for i := 0; i < n; i++ {
		if g[u][i] == 0 {
			continue // Skip if there is no edge between u and i.
		}
		if color[i] == WHITE {
			visit(i) // Recursively visit adjacent white nodes.
		}
	}

	color[u] = BLACK // Set the color of the current node to black.
	f[u] = time + 1  // Record the finishing time.
	time++
}

// The dfs function initializes the time and iterates through all nodes.
func dfs() {
	time = 0 // Initialize the time.

	for i := 0; i < n; i++ {
		if color[i] == WHITE {
			visit(i) // Call visit for any white node.
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i]) // Print the discovery and finishing times of each node.
	}
}

func main() {
	var i, j, x, y, z int

	fmt.Scan(&n) // Read the number of nodes.

	for i = 0; i < n; i++ {
		fmt.Scan(&x, &y)
		for j = 0; j < y; j++ {
			fmt.Scan(&z)
			g[x-1][z-1] = 1 // Populate the adjacency matrix.
		}
	}

	dfs() // Call the dfs function to compute and print the discovery and finishing times.
}

