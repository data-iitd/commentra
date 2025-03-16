package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Create a slice of nodes from 1 to n
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i + 1
	}

	// Read the health points for each node
	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}

	// Create a map to store health points for each node
	hp := make(map[int]int)
	for i := 0; i < n; i++ {
		hp[p[i]] = h[i]
	}

	// Initialize a map to represent the graph as an adjacency list
	path := make(map[int][]int)
	for i := 1; i <= n; i++ {
		path[i] = []int{}
	}

	// Read m edges and populate the adjacency list
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		path[a] = append(path[a], b) // Add edge from a to b
		path[b] = append(path[b], a) // Add edge from b to a (undirected graph)
	}

	// Initialize a counter for nodes that have no neighbors with equal or higher health points
	c := 0

	// Iterate through each node and its connected nodes
	for i, v := range path {
		f := 0 // Flag to check if any neighbor has equal or higher health points
		for _, j := range v {
			// Check if the current node's health is less than or equal to any of its neighbors
			if hp[i] <= hp[j] {
				f = 1 // Set flag if a neighbor with equal or higher health is found
				break // No need to check further neighbors
			}
		}
		// If no neighbors have equal or higher health points, increment the counter
		if f == 0 {
			c++
		}
	}

	// Print the count of nodes that have no neighbors with equal or higher health points
	fmt.Println(c)
}

// <END-OF-CODE>
