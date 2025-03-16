package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	n, ta, ao int
	g         [][]int
	taDist    []int
	aoDist    []int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &ta, &ao)
	ta-- // Adjust to zero-based index
	ao-- // Adjust to zero-based index

	g = make([][]int, n)
	for i := 0; i < n-1; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		g[a-1] = append(g[a-1], b-1) // Append the zero-based index of the neighbor
		g[b-1] = append(g[b-1], a-1) // Append the zero-based index of the neighbor
	}

	taDist = make([]int, n)
	aoDist = make([]int, n)
	for i := range taDist {
		taDist[i] = -1 // Initialize distances to -1 (unvisited)
		aoDist[i] = -1 // Initialize distances to -1 (unvisited)
	}
	taDist[ta] = 0 // Distance from Ta to Ta is 0
	aoDist[ao] = 0 // Distance from Ao to Ao is 0

	// Depth-First Search (DFS) function to compute distances from Ta
	var taDFS func(node int)
	taDFS = func(node int) {
		for _, v := range g[node] {
			if taDist[v] != -1 { // If already visited, skip
				continue
			}
			taDist[v] = taDist[node] + 1 // Update distance
			taDFS(v)                      // Recursively visit neighbors
		}
	}

	// Depth-First Search (DFS) function to compute distances from Ao
	var aoDFS func(node int)
	aoDFS = func(node int) {
		for _, v := range g[node] {
			if aoDist[v] != -1 { // If already visited, skip
				continue
			}
			aoDist[v] = aoDist[node] + 1 // Update distance
			aoDFS(v)                     // Recursively visit neighbors
		}
	}

	// Start DFS from Ao to compute distances
	aoDFS(ao)

	// Start DFS from Ta to compute distances
	taDFS(ta)

	// Initialize result variable
	res := 0

	// Iterate over all nodes to find the maximum distance where Ta's distance is less than or equal to Ao's distance
	for i := 0; i < n; i++ {
		if taDist[i] > aoDist[i] { // Skip if Ta's distance is greater
			continue
		}
		res = max(res, aoDist[i]) // Update result with the maximum distance
	}

	// Print the result, which is the maximum distance minus one
	fmt.Println(res - 1)
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
