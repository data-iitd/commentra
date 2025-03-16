package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define constants for maximum number of nodes and colors
const N = 100
const WHITE = 0
const GRAY = 1
const BLACK = 2

// Adjacency matrix to represent the graph, number of nodes, and arrays for DFS
var M [N][N]int
var n int
var color [N]int
var d [N]int
var f [N]int
var tt int

// Function to visit nodes in DFS
func dfs_visit(u int) {
	var v int
	// Mark the current node as being visited
	color[u] = GRAY
	// Set the discovery time for the current node
	d[u] = tt + 1
	// Explore all adjacent nodes
	for v = 0; v < n; v++ {
		// Skip if there is no edge from u to v
		if M[u][v] == 0 {
			continue
		}
		// If the adjacent node is unvisited, recursively visit it
		if color[v] == WHITE {
			dfs_visit(v)
		}
	}
	// Mark the current node as fully visited
	color[u] = BLACK
	// Set the finish time for the current node
	f[u] = tt + 1
}

// Function to perform DFS on the graph
func dfs() {
	var u int
	// Initialize all nodes as unvisited
	for i := 0; i < n; i++ {
		color[i] = WHITE
	}
	tt = 0 // Reset the time counter
	// Perform DFS for each unvisited node
	for u = 0; u < n; u++ {
		if color[u] == WHITE {
			dfs_visit(u)
		}
	}
	// Output the discovery and finish times for each node
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i + 1, d[i], f[i])
	}
}

func main() {
	var k, u, v int
	// Read the number of nodes
	fmt.Scanf("%d\n", &n)
	// Initialize the adjacency matrix to zero
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0
		}
	}
	// Read the graph edges
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d\n", &u, &k) // Read the node and number of edges
		u-- // Convert to zero-based index
		for j := 0; j < k; j++ {
			fmt.Scanf("%d\n", &v) // Read each adjacent node
			v-- // Convert to zero-based index
			M[u][v] = 1 // Mark the edge in the adjacency matrix
		}
	}
	// Perform DFS on the graph
	dfs()
}

