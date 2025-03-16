package main

import (
	"fmt"
)

const N = 100 // Maximum number of nodes
const WHITE = 0 // Color for unvisited nodes
const GRAY = 1 // Color for nodes being visited
const BLACK = 2 // Color for fully visited nodes

var M [N][N]int // Adjacency matrix to represent the graph
var n int // Number of nodes
var color [N]int // Array to store colors
var d [N]int // Array to store discovery times
var f [N]int // Array to store finish times
var tt int // Time counter

// Function to visit nodes in DFS
func dfsVisit(u int) {
	color[u] = GRAY // Mark the current node as being visited
	tt++
	d[u] = tt // Set the discovery time for the current node

	// Explore all adjacent nodes
	for v := 0; v < n; v++ {
		// Skip if there is no edge from u to v
		if M[u][v] == 0 {
			continue
		}
		// If the adjacent node is unvisited, recursively visit it
		if color[v] == WHITE {
			dfsVisit(v)
		}
	}
	color[u] = BLACK // Mark the current node as fully visited
	tt++
	f[u] = tt // Set the finish time for the current node
}

// Function to perform DFS on the graph
func dfs() {
	for i := 0; i < n; i++ {
		color[i] = WHITE // Initialize all nodes as unvisited
	}
	tt = 0 // Reset the time counter

	// Perform DFS for each unvisited node
	for u := 0; u < n; u++ {
		if color[u] == WHITE {
			dfsVisit(u)
		}
	}

	// Output the discovery and finish times for each node
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	// Read the number of nodes
	fmt.Scan(&n)
	// Initialize the adjacency matrix to zero
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}
	// Read the graph edges
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k) // Read the node and number of edges
		u-- // Convert to zero-based index
		for j := 0; j < k; j++ {
			fmt.Scan(&v) // Read each adjacent node
			v-- // Convert to zero-based index
			M[u][v] = 1 // Mark the edge in the adjacency matrix
		}
	}

	// Perform DFS on the graph
	dfs()
}

// <END-OF-CODE>
