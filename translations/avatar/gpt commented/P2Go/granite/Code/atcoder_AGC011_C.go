
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of nodes (n) and edges (m) from input
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(tokens[0])
	m, _ := strconv.Atoi(tokens[1])

	// Initialize visitation status and counters for isolated components, bipartite components, and non-bipartite components
	vis := make([]int, n+1)
	ci, cb, cc := 0, 0, 0

	// Create an adjacency list to represent the graph
	g := make([][]int, n+1)

	// Define a depth-first search (DFS) function to check for bipartiteness
	dfs := func(x int) bool {
		stk := make([]int, 0)
		flag := true // Initialize flag for bipartiteness
		stk = append(stk, x) // Start DFS from node x with color 1
		stk = append(stk, 1)
		for len(stk) > 0 {
			u := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			if vis[u] > 0 { // If the node has already been visited
				flag = flag && (vis[u] == stk[len(stk)-1]) // Check if the color matches
				continue
			}
			vis[u] = stk[len(stk)-1] // Mark the node as visited with the current color
			for _, i := range g[u] { // Iterate through all adjacent nodes
				stk = append(stk, i) // Push the adjacent node with the alternate color
				stk = append(stk, 3 - stk[len(stk)-1])
			}
		}
		return flag // Return whether the component is bipartite
	}

	// Read edges and build the graph
	for i := 0; i < m; i++ {
		line, _ := reader.ReadString('\n')
		tokens := strings.Split(strings.TrimSpace(line), " ")
		u, _ := strconv.Atoi(tokens[0])
		v, _ := strconv.Atoi(tokens[1])
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

