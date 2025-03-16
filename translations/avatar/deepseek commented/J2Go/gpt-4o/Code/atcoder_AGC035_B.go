package main

import (
	"fmt"
)

var (
	connect [][]int
	visited []int
	odd     []bool
	print   string
)

func main() {
	var numNode, numEdge int
	fmt.Scan(&numNode, &numEdge) // Reading the number of nodes and edges

	// Initializing adjacency lists for each node
	connect = make([][]int, numNode)
	for i := range connect {
		connect[i] = []int{}
	}

	// Reading edges and populating the adjacency lists
	for i := 0; i < numEdge; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Reading node a and b
		a-- // Converting to zero-based index
		b-- // Converting to zero-based index
		connect[a] = append(connect[a], b) // Adding edge from a to b
		connect[b] = append(connect[b], a) // Adding edge from b to a
	}

	// Checking if the number of edges is odd
	if numEdge%2 != 0 {
		fmt.Println(-1) // Printing -1 if the number of edges is odd
		return
	}

	// Initializing arrays for DFS
	visited = make([]int, numNode)
	odd = make([]bool, numNode)

	// Performing DFS starting from node 0
	dfs(0, -1)

	// Outputting the result
	fmt.Print(print)
}

// DFS method to traverse the graph
func dfs(crt, parent int) {
	visited[crt] = 1 // Marking the current node as visited

	// Traversing each child node of the current node
	for _, child := range connect[crt] {
		if child == parent || visited[child] == 1 { // Skipping if the child is the parent or already visited
			continue
		} else if visited[child] == 2 { // Handling the case where the child is part of an already visited cycle
			print += fmt.Sprintf("%d %d\n", crt+1, child+1)
			odd[crt] = !odd[crt]
		} else { // Recursively calling dfs for unvisited child nodes
			dfs(child, crt)
			if odd[child] { // Updating the print and odd arrays based on the child's result
				print += fmt.Sprintf("%d %d\n", child+1, crt+1)
				odd[child] = !odd[child]
			} else {
				print += fmt.Sprintf("%d %d\n", crt+1, child+1)
				odd[crt] = !odd[crt]
			}
		}
	}
	visited[crt] = 2 // Marking the current node as fully processed
}
