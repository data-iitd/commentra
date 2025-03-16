package main

import (
	"fmt"
)

const (
	MAX    = 101          // Define the maximum number of vertices
	WHITE  = 0          // Color constant for unvisited nodes
	BLACK  = 2          // Color constant for fully explored nodes
	GRAY   = 1           // Color constant for nodes currently being explored
)

var (
	time int
	n    int
	g    [MAX][MAX]int
	d    [MAX]int
	f    [MAX]int
	color [MAX]int
)

// Function to perform DFS visit on a node
func visit(u int) {
	color[u] = GRAY // Mark the node as being explored
	d[u] = time + 1 // Set the discovery time for the node
	time++

	// Explore all adjacent nodes
	for i := 0; i < n; i++ {
		if g[u][i] == 0 { // If there is no edge to node i, skip
			continue
		}
		if color[i] == WHITE { // If the adjacent node is unvisited
			visit(i) // Recursively visit the adjacent node
		}
	}

	color[u] = BLACK // Mark the node as fully explored
	f[u] = time + 1 // Set the finish time for the node
	time++
}

// Function to perform Depth-First Search on the graph
func dfs() {
	time = 0 // Initialize time counter

	// Visit all nodes in the graph
	for i := 0; i < n; i++ {
		if color[i] == WHITE { // If the node is unvisited
			visit(i) // Start a DFS visit
		}
	}

	// Print the discovery and finish times for each node
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i]) // Output: node index, discovery time, finish time
	}
}

func main() {
	var i, j, x, y, z int

	// Read the number of vertices
	fmt.Scan(&n)

	// Initialize color array
	for i := 0; i < MAX; i++ {
		color[i] = WHITE
	}

	// Read the graph edges
	for i := 0; i < n; i++ {
		fmt.Scan(&x, &y) // Read the node and the number of edges
		for j := 0; j < y; j++ {
			fmt.Scan(&z) // Read each adjacent node
			g[x-1][z-1] = 1 // Update the adjacency matrix
		}
	}

	// Perform DFS on the graph
	dfs()
}

