package main

import (
	"fmt"
	"os"
)

var (
	graph  [][]int
	mod    = 1000000007
	N, K   int
)

func dfs(fro, to, f int) int {
	// Initialize case number and color number
	caseNum := 0
	if f == K {
		caseNum = 1
	}
	colorNum := K - 1
	if f != K {
		colorNum = K - 2
	}

	// Iterate through the neighbors of the current node
	for _, u := range graph[fro] {
		// Skip the target node
		if u == to {
			continue
		}

		// Recursively call dfs on the neighbor and update case number
		pat := dfs(u, fro, colorNum)
		if pat == 0 {
			caseNum = 0
			break
		}
		caseNum = (caseNum * pat) % mod
		colorNum--
	}

	// Return the final case number
	return caseNum
}

func main() {
	// Read input: number of nodes N and color limit K
	fmt.Scan(&N, &K)

	// Initialize the graph
	graph = make([][]int, N)

	// Read edges between nodes and add them to the graph
	for i := 0; i < N-1; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}

	// Call the dfs function with initial values and print the result
	ans := dfs(0, -1, K)
	fmt.Println(ans)
}

// <END-OF-CODE>
