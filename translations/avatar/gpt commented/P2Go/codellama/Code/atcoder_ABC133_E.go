package main

import (
	"fmt"
	"math"
)

// Define a graph using a map to store adjacency lists
type graph map[int][]int

// Define a recursive function to perform depth-first search (DFS) and count valid colorings
func dfs(fro, to int, f int, g graph) int {
	caseNum := f // Initialize case number with the current color
	colorNum := K - 1
	if f == K {
		colorNum = K - 2
	}

	// Iterate through all adjacent nodes in the graph
	for _, u := range g[fro] {
		if u == to { // Skip the node we came from to avoid cycles
			continue
		}
		pat := dfs(u, fro, colorNum, g) // Recursively call DFS for the adjacent node
		if pat == 0 { // If no valid coloring is found, break out
			caseNum = 0
			break
		}
		caseNum = (caseNum * pat) % mod // Update the case number with the valid patterns found
		colorNum -= 1 // Decrease the available colors for the next node
	}

	return caseNum // Return the total valid colorings found
}

// Define a modulus for the result to prevent overflow
const mod = 1000000007

// Define a function to read the number of nodes (N) and the number of colors (K) from input
func readInput() (int, int) {
	var N, K int
	fmt.Scan(&N, &K)
	return N, K
}

// Define a function to build the graph by reading N-1 edges
func buildGraph(N int) graph {
	g := make(graph)
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	return g
}

// Define a function to print the final answer which is the number of valid colorings
func printAnswer(ans int) {
	fmt.Println(ans)
}

// Define a function to start the DFS from the root node (0) with no parent (-1) and K colors
func startDFS(N, K int, g graph) int {
	return dfs(0, -1, K, g)
}

func main() {
	N, K := readInput() // Read the number of nodes (N) and the number of colors (K) from input
	g := buildGraph(N) // Build the graph by reading N-1 edges
	ans := startDFS(N, K, g) // Start the DFS from the root node (0) with no parent (-1) and K colors
	printAnswer(ans) // Print the final answer which is the number of valid colorings
}

