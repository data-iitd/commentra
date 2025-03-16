
package main

import (
	"fmt"
	"math"
)

// Define a large prime number for modular arithmetic
const mod = 1000000007

// Define infinity for comparison purposes
const INF = math.MaxInt32

// Function to read a single integer from input
func inp() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from input
func inpl() []int {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := range a {
		fmt.Scanf("%d", &a[i])
	}
	return a
}

// Read the number of nodes and the starting points for ta and ao
n, ta, ao := inpl()
ta-- // Adjusting to zero-based index
ao-- // Adjusting to zero-based index

// Initialize the graph as an adjacency list
g := make([][]int, n)

// Read the edges of the graph and populate the adjacency list
for i := 0; i < n-1; i++ {
	a, b := inpl()
	g[a-1] = append(g[a-1], b-1) // Adjusting to zero-based index
	g[b-1] = append(g[b-1], a-1) // Adjusting to zero-based index
}

// Initialize distance arrays for ta and ao
ta_dist := make([]int, n)
ta_dist[ta] = 0 // Distance to itself is 0
ao_dist := make([]int, n)
ao_dist[ao] = 0 // Distance to itself is 0

// Depth-first search (DFS) function to calculate distances from ta
func ta_dfs(node int) {
	for _, v := range g[node] {
		if ta_dist[v] != 0 {
			continue // Skip if already visited
		}
		ta_dist[v] = ta_dist[node] + 1 // Update distance
		ta_dfs(v)                     // Recursive DFS call
	}
}

// Depth-first search (DFS) function to calculate distances from ao
func ao_dfs(node int) {
	for _, v := range g[node] {
		if ao_dist[v] != 0 {
			continue // Skip if already visited
		}
		ao_dist[v] = ao_dist[node] + 1 // Update distance
		ao_dfs(v)                     // Recursive DFS call
	}
}

// Perform DFS from ao to calculate distances
ao_dfs(ao)

// Perform DFS from ta to calculate distances
ta_dfs(ta)

// Initialize result variable to track the maximum distance
res := 0

// Calculate the maximum distance where ta's distance is less than or equal to ao's distance
for i := 0; i < n; i++ {
	if ta_dist[i] > ao_dist[i] {
		continue // Skip if ta is further away than ao
	}
	res = int(math.Max(float64(res), float64(ao_dist[i]))) // Update result with the maximum distance
}

// Print the result, subtracting 1 to adjust for zero-based indexing
fmt.Println(res - 1)

