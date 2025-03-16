package main

import (
	"fmt"
	"os"
)

func readInts() ([]int, error) {
	var n, m int
	_, err := fmt.Scan(&n, &m)
	if err != nil {
		return nil, err
	}
	return []int{n, m}, nil
}

func dfs(g map[int]map[int]struct{}, seen map[int]struct{}, i int) (int, int) {
	if _, ok := seen[i]; ok {
		return 0, 0
	}
	seen[i] = struct{}{} // Mark the current node as seen
	nodes := 1            // Count the current node
	edges := len(g[i])    // Count the edges connected to the current node
	for j := range g[i] {
		x, y := dfs(g, seen, j)
		nodes += x // Accumulate the number of nodes found
		edges += y // Accumulate the number of edges found
	}
	return nodes, edges // Return the total count of nodes and edges
}

func solve() bool {
	line0, err := readInts()
	if err != nil {
		return false // If end of input is reached, return false to stop processing
	}
	n, m := line0[0], line0[1] // Unpack the number of nodes (n) and edges (m)
	g := make(map[int]map[int]struct{}) // Initialize the graph as a map
	seen := make(map[int]struct{})       // Initialize a map to keep track of seen nodes

	for i := 1; i <= n; i++ {
		g[i] = make(map[int]struct{}) // Initialize each node's adjacency list as an empty map
	}
	for j := 0; j < m; j++ {
		var a, b int
		fmt.Scan(&a, &b) // Read each edge
		g[a][b] = struct{}{}
		g[b][a] = struct{}{}
	}
	ans := 0 // Initialize the answer counter
	for i := 1; i <= n; i++ {
		if _, ok := seen[i]; !ok {
			// If the node has not been seen, perform DFS
			nodes, edges := dfs(g, seen, i)
			// Check the conditions for counting valid components
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans++ // Increment the answer if conditions are met
			}
		}
	}
	if (n - ans)%2 == 1 {
		// Adjust the answer if the remaining nodes are odd
		ans++
	}
	fmt.Println(ans) // Output the final answer
	return true      // Return true to indicate successful processing
}

func main() {
	for solve() {
		// Continuously solve the problem until EOF is reached
	}
}

// <END-OF-CODE>
