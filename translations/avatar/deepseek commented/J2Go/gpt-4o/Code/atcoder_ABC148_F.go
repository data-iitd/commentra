package main

import (
	"fmt"
)

func main() {
	var N, u, v int
	fmt.Scan(&N, &u, &v)
	u-- // Convert to 0-based index
	v-- // Convert to 0-based index

	// Step 2: Initialize the adjacency list for the graph
	edges := make([][]int, N)
	for i := 0; i < N; i++ {
		edges[i] = []int{}
	}

	// Step 3: Read the edges of the graph and populate the adjacency list
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-based index
		b-- // Convert to 0-based index
		edges[a] = append(edges[a], b)
		edges[b] = append(edges[b], a)
	}

	// Step 4: Initialize the distance array for the first DFS traversal starting from node u
	d := make([]int, N)
	for i := 0; i < N; i++ {
		d[i] = int(^uint(0) >> 1) // Set to max int
	}
	d[u] = 0

	// Step 5: Perform DFS from node u to populate the distance array d
	dfs(u, d, edges)

	// Step 6: Initialize the distance array for the second DFS traversal starting from node v
	e := make([]int, N)
	for i := 0; i < N; i++ {
		e[i] = int(^uint(0) >> 1) // Set to max int
	}
	e[v] = 0

	// Step 7: Perform DFS from node v to populate the distance array e
	dfs(v, e, edges)

	// Step 8: Find the maximum value of e[i] where d[i] < e[i]
	q := -1
	for i := 0; i < N; i++ {
		if d[i] < e[i] {
			if e[i] > q {
				q = e[i]
			}
		}
	}

	// Step 9: Print the result based on the maximum value found
	if q <= 0 {
		fmt.Println(0)
	} else {
		fmt.Println(q - 1)
	}
}

// Helper method to perform DFS and populate the distance array
func dfs(u int, d []int, edges [][]int) {
	for _, nu := range edges[u] {
		if d[nu] == int(^uint(0) >> 1) { // Check for max int
			d[nu] = d[u] + 1
			dfs(nu, d, edges)
		}
	}
}
