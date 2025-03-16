package main

import (
	"container/list"
	"fmt"
)

var vis []int
var ci, cb, cc int
var g [][]int

// DFS function to check for bipartiteness
func dfs(x int) bool {
	stk := list.New() // Initialize stack for DFS
	stk.PushBack([2]int{x, 1}) // Start DFS from node x with color 1
	flag := true

	for stk.Len() > 0 {
		element := stk.Back()
		stk.Remove(element)
		u, col := element.Value.([2]int)[0], element.Value.([2]int)[1]

		if vis[u] != 0 { // If the node has already been visited
			flag = flag && (vis[u] == col) // Check if the color matches
			continue
		}
		vis[u] = col // Mark the node as visited with the current color
		for _, i := range g[u] { // Iterate through all adjacent nodes
			stk.PushBack([2]int{i, 3 - col}) // Push the adjacent node with the alternate color
		}
	}
	return flag // Return whether the component is bipartite
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize visitation status and counters
	vis = make([]int, n+1)
	g = make([][]int, n+1)

	// Read edges and build the graph
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
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
	result := ci*ci + 2*ci*(n-ci) + cc*cc + 2*cb*cc + 2*cb*cb
	fmt.Println(result)
}

// <END-OF-CODE>
