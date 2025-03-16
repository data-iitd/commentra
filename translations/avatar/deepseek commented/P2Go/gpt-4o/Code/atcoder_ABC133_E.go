package main

import (
	"fmt"
	"os"
)

var graph [][]int
var mod int64 = 1_000_000_007

func dfs(fro, to, f int) int64 {
	caseNum := int64(f) // Initialize the number of valid colorings with the initial number of colors
	colorNum := K - 1
	if f == K {
		colorNum = K - 2
	}
	for _, u := range graph[fro] {
		if u == to {
			continue // Skip if the neighbor is the parent node
		}
		pat := dfs(u, fro, colorNum) // Recursively call dfs for the neighbor
		if pat == 0 {
			return 0 // If no valid colorings, return 0
		}
		caseNum = (caseNum * pat) % mod // Multiply the current number of valid colorings by the recursive result
		colorNum-- // Decrease the number of available colors for the next node
	}
	return caseNum // Return the number of valid colorings for the current node
}

var N, K int

func main() {
	fmt.Scan(&N, &K) // Read the number of nodes and the number of colors
	graph = make([][]int, N) // Initialize the graph

	// Construct the graph by reading edges
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		graph[a-1] = append(graph[a-1], b-1) // Append the edge to the graph
		graph[b-1] = append(graph[b-1], a-1) // Since the graph is undirected, append the reverse edge as well
	}

	ans := dfs(0, -1, K) // Call the dfs function starting from the root node with the initial number of colors
	fmt.Println(ans) // Print the final result
}

// <END-OF-CODE>
