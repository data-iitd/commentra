
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize scanner to read input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of nodes and edges from input
	var numNode, numEdge int
	fmt.Scan(&numNode, &numEdge)

	// Create an adjacency list to represent the graph
	connect := make([][]int, numNode)
	for i := 0; i < numNode; i++ {
		connect[i] = make([]int, 0) // Initialize each list in the adjacency list
	}

	// Read edges and populate the adjacency list
	for i := 0; i < numEdge; i++ {
		var a, b int
		fmt.Scan(&a, &b) // Read first node of the edge (0-indexed)
		connect[a-1] = append(connect[a-1], b-1) // Add edge in both directions (undirected graph)
		connect[b-1] = append(connect[b-1], a-1)
	}

	// Check if the number of edges is odd; if so, output -1 and exit
	if numEdge%2 != 0 {
		fmt.Println(-1)
		return
	}

	// Initialize arrays for tracking visited nodes and odd/even connections
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	print := strings.Builder{} // StringBuilder to accumulate output

	// Perform depth-first search starting from node 0
	dfs(0, -1)

	// Output the result
	fmt.Println(print)
}

// Declare global variables for the graph representation and state tracking
var connect [][]int
var visited []int
var odd []bool
var print strings.Builder

// Depth-first search method to explore the graph
func dfs(crt, parent int) {
	visited[crt] = 1 // Mark the current node as visited
	crtConnect := connect[crt] // Get the current node's connections

	// Iterate through each child node connected to the current node
	for _, child := range crtConnect {
		// Skip the parent node and already visited nodes
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			// If the child has been fully processed, append the edge to output
			print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
			odd[crt] = !odd[crt] // Toggle the odd/even state
		} else {
			// Recursively call DFS on the child node
			dfs(child, crt)

			// Check the odd/even state of the child node after DFS
			if odd[child] {
				print.WriteString(strconv.Itoa(child+1) + " " + strconv.Itoa(crt+1) + "\n")
				odd[child] = !odd[child] // Toggle the state
			} else {
				print.WriteString(strconv.Itoa(crt+1) + " " + strconv.Itoa(child+1) + "\n")
				odd[crt] = !odd[crt] // Toggle the state
			}
		}
	}
	visited[crt] = 2 // Mark the current node as fully processed
}

