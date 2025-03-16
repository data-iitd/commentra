package main

import (
	"fmt"
	"os"
)

var graph [][]int
var mod int64 = 1e9 + 7

func dfs(fro, to, f int) int64 {
	caseNum := int64(f) // Initialize case number with the current color
	colorNum := K - 1
	if f == K {
		colorNum = K - 2 // Determine the number of available colors for the next node
	}

	for _, u := range graph[fro] {
		if u == to { // Skip the node we came from to avoid cycles
			continue
		}
		pat := dfs(u, fro, colorNum) // Recursively call DFS for the adjacent node
		if pat == 0 { // If no valid coloring is found, break out
			caseNum = 0
			break
		}
		caseNum = (caseNum * pat) % mod // Update the case number with the valid patterns found
		colorNum-- // Decrease the available colors for the next node
	}

	return caseNum // Return the total valid colorings found
}

var N, K int

func main() {
	fmt.Scan(&N, &K) // Read the number of nodes (N) and the number of colors (K)

	graph = make([][]int, N) // Initialize the graph

	// Build the graph by reading N-1 edges
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read each edge
		graph[a-1] = append(graph[a-1], b-1) // Add edge from a to b (0-indexed)
		graph[b-1] = append(graph[b-1], a-1) // Add edge from b to a (0-indexed)
	}

	// Start the DFS from the root node (0) with no parent (-1) and K colors
	ans := dfs(0, -1, K)

	// Print the final answer which is the number of valid colorings
	fmt.Println(ans)
}

// <END-OF-CODE>
