package main

import (
	"fmt"
)

const N = 100 // Define the maximum number of nodes
const WHITE = 0 // Define WHITE color
const GRAY = 1 // Define GRAY color
const BLACK = 2 // Define BLACK color

var M [N][N]int // Declare the adjacency matrix
var n int // Number of nodes
var color [N]int // Color of nodes
var d [N]int // Discovery time
var f [N]int // Finish time
var tt int // Time counter

// Depth-first search visit function
func dfsVisit(u int) {
	color[u] = GRAY // Set the color of node u to GRAY
	tt++ // Increment time counter
	d[u] = tt // Record the discovery time of u
	for v := 0; v < n; v++ {
		if M[u][v] == 0 {
			continue // Skip if there is no edge from u to v
		}
		if color[v] == WHITE { // If v is WHITE, recursively visit v
			dfsVisit(v)
		}
	}
	color[u] = BLACK // Set the color of node u to BLACK
	tt++ // Increment time counter
	f[u] = tt // Record the finish time of u
}

// Depth-first search function
func dfs() {
	for i := 0; i < n; i++ {
		color[i] = WHITE // Initialize all nodes to WHITE
	}
	tt = 0 // Reset the time counter

	for u := 0; u < n; u++ {
		if color[u] == WHITE { // If u is WHITE, start a DFS from u
			dfsVisit(u)
		}
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i]) // Print the discovery and finish times for each node
	}
}

func main() {
	var k, u, v int
	fmt.Scan(&n) // Read the number of nodes
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			M[i][j] = 0 // Initialize the adjacency matrix
		}
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&u, &k) // Read the node and the number of its neighbors
		u-- // Convert to 0-based index
		for j := 0; j < k; j++ {
			fmt.Scan(&v) // Read the neighbor
			v-- // Convert to 0-based index
			M[u][v] = 1 // Set the edge in the adjacency matrix
		}
	}

	dfs() // Perform the depth-first search and print the results
}

// <END-OF-CODE>
