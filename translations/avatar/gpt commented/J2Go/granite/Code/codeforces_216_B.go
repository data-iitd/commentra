
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Variable to count the number of nodes in the current DFS traversal
var count int
// Array to track which nodes have been visited
var seen []bool
// Constants to represent the state of the traversal
const path = 0
const cycle = 1
// Adjacency list representation of the graph
var graph [][]int

// Depth-First Search (DFS) method to explore the graph
func dfs(child, par int) int {
	// If the current node has already been seen, return cycle indicator
	if seen[child] == true {
		return cycle
	}
	// Mark the current node as seen
	seen[child] = true

	// Iterate through all adjacent nodes of the current node
	for _, i := range graph[child] {
		// Avoid going back to the parent node
		if i!= par {
			count++ // Increment the count of nodes visited
			// Recursively call DFS on the adjacent node
			if dfs(i, child) == cycle {
				return cycle // Check for cycles
			}
		}
	}
	// Return path indicator if no cycle is found
	return path
}

func main() {
	// Create a scanner object for input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of nodes (m) and edges (n)
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Create an instance of Main to access graph and related variables
	graph = make([][]int, m+1)

	// Initialize the graph with empty slices for each node
	for i := 0; i <= m; i++ {
		graph[i] = make([]int, 0)
	}

	// Initialize the seen array to track visited nodes
	seen = make([]bool, m+1)

	// Read the edges and populate the graph
	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		// Add the edge in both directions (undirected graph)
		graph[x] = append(graph[x], y)
		graph[y] = append(graph[y], x)
	}

	// Variable to count the number of nodes to remove
	toremove := 0

	// Iterate through all nodes to check for unvisited nodes
	for i := 1; i <= m; i++ {
		// If the node has not been seen, perform DFS
		if!seen[i] {
			count = 0 // Reset count for the new component
			// Check if the DFS from this node finds a cycle
			if dfs(i, 0) == cycle {
				// If a cycle is found and the count of nodes is odd, increment toremove
				if count%2 == 1 {
					toremove++
				}
			}
		}
	}

	// Adjust the number of nodes to remove if the remaining nodes are odd
	if (m-toremove)%2 == 1 {
		toremove++
	}

	// Output the result: number of nodes to remove
	fmt.Println(toremove)
}

// END-OF-CODE