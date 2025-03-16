// Package main is the entry point of the program
package main

import "fmt"

// Define a 2D slice 'e' to store the edges of the graph
var e [][]int

// Define variables 'n' and 'm' to store the number of nodes and edges respectively
var n, m int

// Function 'printEdge' to print the edges of the graph
func printEdge(e [][]int) {
	// Iterate through each node in the graph
	for i := 1; i < n+1; i++ {
		// Print the node number and its connected nodes
		fmt.Printf("%d: ", i)
		for _, v := range e[i] {
			fmt.Printf("%d ", v)
		}
		fmt.Println()
	}
}

// Function 'dfs' to perform Depth First Search traversal
func dfs(v int, visited []bool) int {
	// Initialize a boolean slice 'visited' to keep track of visited nodes
	// visited[v] = true
	// fmt.Println(v, visited)

	// Check if all nodes are visited, if yes then it's a strongly connected component
	comp := true
	for i := 1; i < n+1; i++ {
		if !visited[i] {
			comp = false
			break
		}
	}

	// If all nodes are visited, return 1 for this strongly connected component
	if comp {
		return 1
	}

	// Initialize a counter 'count' to store the size of the strongly connected component
	count := 0
	// Iterate through the neighbors of the current node 'v'
	for _, ne := range e[v] {
		// If the neighbor is already visited, skip it
		if visited[ne] {
			continue
		}
		// Mark the neighbor as visited
		visited[ne] = true
		// Recursively call 'dfs' on the neighbor and add its size to the counter
		// rst := dfs(ne, visited, count)
		// count += rst
		rst := dfs(ne, visited)
		count += rst
		// Mark the neighbor as unvisited
		visited[ne] = false
	}
	// Return the size of the strongly connected component
	return count
}

// Function 'main' to read input and call the 'printEdge' and 'dfs' functions
func main() {
	// Read the number of nodes and edges from the standard input
	fmt.Scan(&n, &m)

	// Initialize a 2D slice 'e' of size (n+1)x(n+1) to store the edges of the graph
	e = make([][]int, n+1)
	for i := 1; i < n+1; i++ {
		// Initialize an empty slice for each node
		e[i] = make([]int, 0)
	}
	// Read the edges of the graph from the standard input and add them to the 'e' slice
	for i := 0; i < m; i++ {
		var a, b int
		// Read the nodes of an edge from the standard input
		fmt.Scan(&a, &b)
		// Add the edge to the 'e' slice for both nodes
		e[a] = append(e[a], b)
		e[b] = append(e[b], a)
	}
	// Call the 'printEdge' function to print the edges of the graph
	// printEdge(e)

	// Initialize a boolean slice 'visited' of size (n+1) to keep track of visited nodes
	visited := make([]bool, n+1)
	// Mark the first node as visited
	visited[1] = true
	// Call the 'dfs' function on the first node and print the size of the strongly connected component
	count := dfs(1, visited)
	fmt.Println(count)
}

