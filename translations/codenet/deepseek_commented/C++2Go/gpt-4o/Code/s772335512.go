package main

import (
	"fmt"
)

var (
	// G is a slice of slices representing the graph.
	G     [][]int
	used  []bool
	grundy []int
)

// dfs function performs a depth-first search on the graph.
func dfs(v int) {
	// Mark the current node as visited.
	used[v] = true
	// Initialize the Grundy number of the current node to 0.
	grundy[v] = 0
	// Iterate through all the neighbors of the current node.
	for _, neighbor := range G[v] {
		// If a neighbor has not been visited, recursively call dfs on that neighbor.
		if !used[neighbor] {
			dfs(neighbor)
			// Update the Grundy number of the current node.
			grundy[v] ^= (grundy[neighbor] + 1)
		}
	}
}

func main() {
	// Read the number of nodes N.
	var N int
	fmt.Scan(&N)

	// Initialize the graph, used array, and grundy array.
	G = make([][]int, N)
	used = make([]bool, N)
	grundy = make([]int, N)

	// Read the edges of the graph and construct the adjacency list.
	for i := 0; i < N-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x-- // Convert to 0-based index
		y-- // Convert to 0-based index
		G[x] = append(G[x], y)
		G[y] = append(G[y], x)
	}

	// Call the dfs function starting from node 0.
	dfs(0)

	// Check the Grundy number of the root node (node 0).
	if grundy[0] != 0 {
		// Print "Alice" if the Grundy number is not 0, otherwise print "Bob".
		fmt.Println("Alice")
	} else {
		fmt.Println("Bob")
	}
}

// <END-OF-CODE>
