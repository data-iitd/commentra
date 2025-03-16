
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of nodes (n) and edges (m) from input
	n, m := readInts()

	// Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
	vis, ci, cb, cc := make([]int, n+1), 0, 0, 0

	// Create an adjacency list to represent the graph
	g := make([][]int, n+1)

	// Define a depth-first search (DFS) function to check for bipartiteness
	var dfs func(int) bool
	dfs = func(x int) bool {
		stk, flag := make([][2]int, 0), true
		stk = append(stk, [2]int{x, 1}) // Start DFS from node x with color 1
		for len(stk) > 0 {
			u, col := stk[len(stk)-1][0], stk[len(stk)-1][1]
			stk = stk[:len(stk)-1]
			if vis[u] != 0 { // If the node has already been visited
				flag = flag && (vis[u] == col) // Check if the color matches
				continue
			}
			vis[u] = col // Mark the node as visited with the current color
			for _, i := range g[u] { // Iterate through all adjacent nodes
				stk = append(stk, [2]int{i, 3 - col}) // Push the adjacent node with the alternate color
			}
		}
		return flag // Return whether the component is bipartite
	}

	// Read edges and build the graph
	for i := 0; i < m; i++ {
		u, v := readInts()
		g[u] = append(g[u], v) // Add edge from u to v
		g[v] = append(g[v], u) // Add edge from v to u (undirected graph)
	}

	// Iterate through all nodes to count isolated and bipartite components
	for i := 1; i <= n; i++ {
		if vis[i] == 0 { // If the node has not been visited
			if len(g[i]) == 0 { // Check if the node is isolated
				ci++ // Increment isolated component counter
			} else {
				if dfs(i) { // Perform DFS and check if the component is bipartite
					cb++ // Increment bipartite component counter
				} else {
					cc++ // Increment non-bipartite component counter
				}
			}
		}
	}

	// Calculate and print the final result based on the counts of components
	fmt.Println(ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb)
}

func readInts() (int, int) {
	var n, m int
	fmt.Scan(&n, &m)
	return n, m
}

