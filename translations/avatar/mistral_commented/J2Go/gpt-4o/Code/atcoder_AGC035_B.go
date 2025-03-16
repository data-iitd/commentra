package main

import (
	"fmt"
)

// Main function where the program starts execution.
func main() {
	var numNode, numEdge int
	fmt.Scan(&numNode) // Reading the number of nodes from the input.
	fmt.Scan(&numEdge) // Reading the number of edges from the input.

	// Initializing the connect slice to store the list of neighbors for each node.
	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = []int{}
	}

	// Reading the edges and adding them to the connect slice.
	for i := 0; i < numEdge; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Reading the two nodes of the edge.
		a-- // Adjusting index to be zero-based.
		b-- // Adjusting index to be zero-based.
		connect[a] = append(connect[a], b) // Adding the second node index to the first node's list of neighbors.
		connect[b] = append(connect[b], a) // Adding the first node index to the second node's list of neighbors.
	}

	// Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initializing the visited, odd, and print variables.
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	var print string

	// Calling the dfs function with the first node and -1 as the parent node.
	print = dfs(0, -1, connect, visited, odd, print)

	// Printing the output.
	fmt.Print(print)
}

// Recursive depth-first search function to perform bipartite traversal.
func dfs(crt, parent int, connect [][]int, visited []int, odd []bool, print string) string {
	// Marking the current node as visited.
	visited[crt] = 1

	// Iterating through the neighbors of the current node.
	for _, child := range connect[crt] {
		// Skipping the neighbor if it is the parent node or already visited.
		if child == parent || visited[child] == 1 {
			continue
		}

		// If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
		// Otherwise, we swap the components and continue the traversal.
		if visited[child] == 2 {
			print += fmt.Sprintf("%d %d\n", crt+1, child+1)
			odd[crt] = !odd[crt]
		} else {
			print = dfs(child, crt, connect, visited, odd, print)
			if odd[child] {
				print += fmt.Sprintf("%d %d\n", child+1, crt+1)
				odd[child] = !odd[child]
			} else {
				print += fmt.Sprintf("%d %d\n", crt+1, child+1)
				odd[crt] = !odd[crt]
			}
		}
	}

	// Marking the current node as visited with component 2.
	visited[crt] = 2
	return print
}
