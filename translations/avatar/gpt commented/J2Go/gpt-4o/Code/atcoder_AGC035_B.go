package main

import (
	"fmt"
)

var (
	connect [][]int
	visited  []int
	odd      []bool
	print    string
)

func main() {
	// Initialize scanner to read input
	var numNode, numEdge int
	fmt.Scan(&numNode, &numEdge)

	// Create an adjacency list to represent the graph
	connect = make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = []int{} // Initialize each list in the adjacency list
	}

	// Read edges and populate the adjacency list
	for i := 0; i < numEdge; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		a-- // Convert to 0-indexed
		b-- // Convert to 0-indexed
		connect[a] = append(connect[a], b) // Add edge in both directions (undirected graph)
		connect[b] = append(connect[b], a)
	}

	// Check if the number of edges is odd; if so, output -1 and exit
	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initialize arrays for tracking visited nodes and odd/even connections
	visited = make([]int, numNode)
	odd = make([]bool, numNode)

	// Perform depth-first search starting from node 0
	dfs(0, -1)

	// Output the result
	fmt.Print(print)
}

// Depth-first search method to explore the graph
func dfs(crt, parent int) {
	visited[crt] = 1 // Mark the current node as visited

	// Iterate through each child node connected to the current node
	for _, child := range connect[crt] {
		// Skip the parent node and already visited nodes
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			// If the child has been fully processed, append the edge to output
			print += fmt.Sprintf("%d %d\n", crt+1, child+1)
			odd[crt] = !odd[crt] // Toggle the odd/even state
		} else {
			// Recursively call DFS on the child node
			dfs(child, crt)

			// Check the odd/even state of the child node after DFS
			if odd[child] {
				print += fmt.Sprintf("%d %d\n", child+1, crt+1)
				odd[child] = !odd[child] // Toggle the state
			} else {
				print += fmt.Sprintf("%d %d\n", crt+1, child+1)
				odd[crt] = !odd[crt] // Toggle the state
			}
		}
	}
	visited[crt] = 2 // Mark the current node as fully processed
}

// <END-OF-CODE>
