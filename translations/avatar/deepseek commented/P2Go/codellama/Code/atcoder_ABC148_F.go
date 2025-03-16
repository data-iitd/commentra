
package main

import (
	"fmt"
)

// Function to read an integer from standard input
func inp() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read a list of integers from standard input
func inpl() []int {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	return a
}

// Read the number of nodes, starting node for Ta, and starting node for Ao
n, ta, ao := inpl()

// Adjust indices to be zero-based
ta--
ao--

// Initialize the graph as a list of lists, each representing adjacency list of a node
g := make([][]int, n)

// Read edges to construct the graph
for i := 0; i < n-1; i++ {
	a, b := inpl()
	g[a-1] = append(g[a-1], b-1)  // Append the zero-based index of the neighbor
	g[b-1] = append(g[b-1], a-1)  // Append the zero-based index of the neighbor
}

// Initialize distance arrays to -1, will be populated during DFS
ta_dist := make([]int, n)
ta_dist[ta] = 0  // Distance from Ta to Ta is 0
ao_dist := make([]int, n)
ao_dist[ao] = 0  // Distance from Ao to Ao is 0

// Depth-First Search (DFS) function to compute distances from Ta
func ta_dfs(node int) {
	for _, v := range g[node] {
		if ta_dist[v] != -1 {  // If already visited, skip
			continue
		}
		ta_dist[v] = ta_dist[node] + 1  // Update distance
		ta_dfs(v)  // Recursively visit neighbors
	}
}

// Depth-First Search (DFS) function to compute distances from Ao
func ao_dfs(node int) {
	for _, v := range g[node] {
		if ao_dist[v] != -1 {  // If already visited, skip
			continue
		}
		ao_dist[v] = ao_dist[node] + 1  // Update distance
		ao_dfs(v)  // Recursively visit neighbors
	}
}

// Start DFS from Ao to compute distances
ao_dfs(ao)

// Start DFS from Ta to compute distances
ta_dfs(ta)

// Initialize result variable
res := 0

// Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
for i := 0; i < n; i++ {
	if ta_dist[i] > ao_dist[i] {  // Skip if Ta's distance is greater
		continue
	}
	res = max(res, ao_dist[i])  // Update result with the maximum distance
}

// Print the result, which is the maximum distance minus one
fmt.Println(res - 1)

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

