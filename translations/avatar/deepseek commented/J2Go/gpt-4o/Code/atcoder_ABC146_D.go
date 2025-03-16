package main

import (
	"fmt"
)

type Edge struct {
	id int
	to int
}

var n int
var g [][]Edge // Graph as an adjacency list
var ans []int  // Answer array to store edge colors

func main() {
	fmt.Scan(&n) // Read the number of nodes
	g = make([][]Edge, n) // Initialize the graph
	for i := 0; i < n-1; i++ { // Read and populate the graph
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to zero-based index
		b-- // Convert to zero-based index
		g[a] = append(g[a], Edge{id: i, to: b}) // Add edge from a to b
		g[b] = append(g[b], Edge{id: i, to: a}) // Add edge from b to a
	}
	ans = make([]int, n-1) // Initialize the answer array
	dfs(0, -1, -1) // Call DFS with root node 0, initial color -1, and parent -1

	max := 0 // Initialize max to find the maximum color used
	for _, temp := range ans {
		if temp > max {
			max = temp // Find the maximum color used
		}
	}
	fmt.Println(max) // Print the maximum color used
	for _, c := range ans {
		fmt.Println(c) // Print the colors assigned to each edge
	}
}

func dfs(to, color, parent int) { // Define the DFS function
	k := 1 // Initialize the color counter
	for _, e := range g[to] { // Iterate through the adjacency list of the current node
		if e.to == parent {
			continue // Skip if the neighbor is the parent
		}
		if k == color {
			k++ // Ensure the color is not the same as the parent's color
		}
		ans[e.id] = k // Assign the color to the edge
		dfs(e.to, k, to) // Recursively call DFS for the neighbor
		k++ // Increment the color counter for the next edge
	}
}

// <END-OF-CODE>
