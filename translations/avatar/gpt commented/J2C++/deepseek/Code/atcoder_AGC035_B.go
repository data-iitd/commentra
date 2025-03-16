package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of nodes and edges from input
	scanner.Scan()
	numNode := 0
	fmt.Sscanf(scanner.Text(), "%d", &numNode)
	scanner.Scan()
	numEdge := 0
	fmt.Sscanf(scanner.Text(), "%d", &numEdge)
	
	// Create a slice to represent the graph adjacency list
	var connect [][]int
	for i := 0; i < numNode; i++ {
		connect = append(connect, []int{})
	}
	
	// Read edges and populate the adjacency list
	for i := 0; i < numEdge; i++ {
		scanner.Scan()
		var a, b int
		fmt.Sscanf(scanner.Text(), "%d %d", &a, &b)
		a-- // Convert to 0-indexed
		b-- // Convert to 0-indexed
		connect[a] = append(connect[a], b)
		connect[b] = append(connect[b], a)
	}
	
	// Check if the number of edges is odd; if so, output -1 and exit
	if numEdge % 2 != 0 {
		fmt.Println(-1)
		return
	}
	
	// Initialize slices for tracking visited nodes and odd/even connections
	visited := make([]int, numNode)
	odd := make([]bool, numNode)
	var print strings.Builder
	
	// Perform depth-first search starting from node 0
	dfs(0, -1, connect, visited, odd, &print)
	
	// Output the result
	fmt.Println(print.String())
}

// Depth-first search method to explore the graph
func dfs(crt, parent int, connect [][]int, visited []int, odd []bool, print *strings.Builder) {
	visited[crt] = 1 // Mark the current node as visited
	
	// Iterate through each child node connected to the current node
	for _, child := range connect[crt] {
		// Skip the parent node and already visited nodes
		if child == parent || visited[child] == 1 {
			continue
		} else if visited[child] == 2 {
			// If the child has been fully processed, append the edge to output
			print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
			odd[crt] = !odd[crt] // Toggle the odd/even state
		} else {
			// Recursively call DFS on the child node
			dfs(child, crt, connect, visited, odd, print)
			
			// Check the odd/even state of the child node after DFS
			if odd[child] {
				print.WriteString(fmt.Sprintf("%d %d\n", child+1, crt+1))
				odd[child] = !odd[child] // Toggle the state
			} else {
				print.WriteString(fmt.Sprintf("%d %d\n", crt+1, child+1))
				odd[crt] = !odd[crt] // Toggle the state
			}
		}
	}
	visited[crt] = 2 // Mark the current node as fully processed
}
