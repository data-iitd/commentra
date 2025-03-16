package main

import (
	"fmt"
	"os"
)

type Graph map[int]map[int]struct{}

// Function to read an array of integers from standard input
func readInts() ([]int, error) {
	var n int
	var err error
	var nums []int
	for {
		_, err = fmt.Scan(&n)
		if err != nil {
			break
		}
		nums = append(nums, n)
	}
	return nums, err
}

// Depth First Search (DFS) function to traverse the graph and calculate nodes and edges for a given vertex
func dfs(g Graph, seen map[int]struct{}, i int) (int, int) {
	// Base case: if the current vertex is already in the seen set, return 0 for nodes and 0 for edges
	if _, ok := seen[i]; ok {
		return 0, 0
	}

	// Mark the current vertex as visited by adding it to the seen set
	seen[i] = struct{}{}

	// Initialize nodes and edges counters
	nodes := 1
	edges := len(g[i])

	// Recursively traverse the graph for all neighbors of the current vertex
	for j := range g[i] {
		// Recursive call to DFS function for the neighbor vertex
		x, y := dfs(g, seen, j)

		// Update nodes and edges counters based on the result of the recursive call
		nodes += x
		edges += y
	}

	// Return the final count of nodes and edges for the current vertex
	return nodes, edges
}

// Main function to solve the problem
func solve() bool {
	// Read the first line of input containing the number of vertices and edges in the graph
	line0, err := readInts()
	if err != nil {
		return false
	}

	n, m := line0[0], line0[1] // Extract the number of vertices and edges from the input line

	// Initialize the graph as a map with vertices as keys and empty maps as values
	g := make(Graph)
	seen := make(map[int]struct{})

	// Initialize an empty map to store the neighbors of each vertex
	for i := 1; i <= n; i++ {
		g[i] = make(map[int]struct{})
	}

	// Read the remaining lines of input containing the edges of the graph and add them to the graph
	for j := 0; j < m; j++ {
		edge, err := readInts()
		if err != nil {
			break
		}
		a, b := edge[0], edge[1]
		g[a][b] = struct{}{}
		g[b][a] = struct{}{}
	}

	// Initialize the answer counter to 0
	ans := 0

	// Traverse the graph using DFS function for each unvisited vertex and check if it satisfies the condition
	for i := 1; i <= n; i++ {
		if _, ok := seen[i]; !ok {
			nodes, edges := dfs(g, seen, i)
			if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
				ans++
			}
		}
	}

	// Update the answer counter based on the parity of the total number of vertices
	if (n-ans)%2 == 1 {
		ans++
	}

	// Print the final answer and return true to indicate the success of the program
	fmt.Println(ans)
	return true
}

// Main loop to repeatedly call the solve function until there is no more input
func main() {
	for solve() {
	}
}

// <END-OF-CODE>
