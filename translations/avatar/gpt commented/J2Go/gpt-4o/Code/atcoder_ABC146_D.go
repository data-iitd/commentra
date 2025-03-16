package main

import (
	"fmt"
)

type Edge struct {
	id int // Unique identifier for the edge
	to int // Destination node of the edge
}

var (
	n   int           // Number of nodes in the graph
	g   [][]Edge      // Adjacency list representation of the graph
	ans []int         // Array to store the answer for each edge
)

func main() {
	// Read the number of nodes
	fmt.Scan(&n)

	// Initialize the adjacency list for the graph
	g = make([][]Edge, n)

	// Read edges and populate the adjacency list
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Adjust for 0-based indexing
		b-- // Adjust for 0-based indexing
		// Add the edge to both endpoints' adjacency lists
		g[a] = append(g[a], Edge{id: i, to: b})
		g[b] = append(g[b], Edge{id: i, to: a})
	}

	// Initialize the answer array to store results for each edge
	ans = make([]int, n-1)

	// Perform a depth-first search starting from node 0
	dfs(0, -1, -1)

	// Find the maximum value in the ans array
	max := 0
	for _, temp := range ans {
		if temp > max {
			max = temp
		}
	}

	// Output the maximum value found
	fmt.Println(max)

	// Output the results for each edge
	for _, c := range ans {
		fmt.Println(c)
	}
}

// Depth-first search function to traverse the graph and assign colors to edges
func dfs(to, color, parents int) {
	k := 1 // Start coloring with color 1
	for _, e := range g[to] {
		// Skip the edge leading back to the parent node
		if e.to == parents {
			continue
		}
		// If the current color is the same as the edge color, increment it
		if k == color {
			k++
		}
		// Assign the color to the edge
		ans[e.id] = k
		// Recursively call dfs for the connected node
		dfs(e.to, k, to)
		k++ // Increment color for the next edge
	}
}

// <END-OF-CODE>
