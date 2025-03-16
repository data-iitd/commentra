package main

import (
	"fmt"
)

func main() {
	var N, u, v int
	fmt.Scan(&N)
	fmt.Scan(&u, &v)
	u-- // Convert to zero-based index
	v-- // Convert to zero-based index

	// Initialize the adjacency lists for the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = []int{}
	}

	// Read the edges of the graph from the standard input and add them to the adjacency lists
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to zero-based index
		b-- // Convert to zero-based index
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	// Initialize the distance arrays d and e for depth-first search
	d := make([]int, N)
	for i := range d {
		d[i] = int(^uint(0) >> 1) // Set to max int
	}
	e := make([]int, N)
	for i := range e {
		e[i] = int(^uint(0) >> 1) // Set to max int
	}

	// Perform depth-first search from nodes u and v and store the distances in arrays d and e, respectively
	dfs(u, d, edges)
	dfs(v, e, edges)

	// Find the maximum difference between the distances of any node from u and v
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}

	// Print the result: the maximum difference between the distances of any node from u and v
	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

// Depth-first search recursive helper method
func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == int(^uint(0)>>1) { // Check if the node is unvisited
			// Mark the current node as visited and update the distance of its neighbors
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}
