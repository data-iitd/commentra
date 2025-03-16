package main

import (
	"fmt"
)

const MAXN = 100000

// Declare a graph represented as an adjacency list
var G [MAXN][]int
// Array to track visited nodes during DFS
var used [MAXN]bool
// Array to store the Grundy values for each node
var grundy [MAXN]int

// Depth-First Search (DFS) function to compute Grundy values
func dfs(v int) {
	// Mark the current node as visited
	used[v] = true
	// Initialize the Grundy value for the current node
	grundy[v] = 0

	// Iterate through all adjacent nodes
	for _, neighbor := range G[v] {
		// If the adjacent node has not been visited
		if !used[neighbor] {
			// Recursively perform DFS on the adjacent node
			dfs(neighbor)
			// Update the Grundy value using the Grundy value of the child node
			grundy[v] ^= (grundy[neighbor] + 1)
		}
	}
}

func main() {
	// Read the number of nodes in the graph
	var N int
	fmt.Scan(&N)

	// Read the edges of the graph
	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		// Convert to zero-based indexing
		x--
		y--
		// Add the edge to the adjacency list
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}

	// Start DFS from the root node (node 0)
	dfs(0)

	// Determine the winner based on the Grundy value of the root node
	if grundy[0] != 0 {
		fmt.Println("Alice") // Alice wins if Grundy value is non-zero
	} else {
		fmt.Println("Bob")   // Bob wins if Grundy value is zero
	}
}

// <END-OF-CODE>
